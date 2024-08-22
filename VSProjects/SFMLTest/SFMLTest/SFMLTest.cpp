#include "Logic.h"


int main()
{
	// Create the window
	RenderWindow window(VideoMode::getFullscreenModes()[0], "Space Shooter", Style::Fullscreen);

	const int enemy_starting_y = static_cast<int>(window.getSize().y / 5);

	// Setup font
	Font font = fontloader("arial.ttf");

	// Set up the text for the score and lives
	pair<Text, Text> loaded_texts;
	loaded_texts = textsetup(font);
	Text score_text = loaded_texts.first;
	Text lives_text = loaded_texts.second;
	int score = 0;
	int lives = 3;

	// Set up player and enemy textures
	pair<Texture, Texture> loaded_textures;
	loaded_textures = textureloader("ship02.png", "enemy01.png");
	Texture player_texture = loaded_textures.first;
	Texture enemy_texture = loaded_textures.second;

	// Apply the sprites
	pair<Sprite, Sprite> loaded_sprites;
	loaded_sprites = spritesetup(player_texture, enemy_texture, window);
	Sprite player = loaded_sprites.first;
	vector<Sprite> enemies;
	Sprite enemy;
	for (int i = 0; i < 5; i++)
	{
		enemy = loaded_sprites.second;
		enemy.setPosition(rand() % window.getSize().x, - (rand() % enemy_starting_y));
		enemies.push_back(enemy);
	}
	float player_speed = window.getSize().x / 800.0f;
	float enemy_speed = window.getSize().y / 8000.0f;

	// Set up the bullets
	RectangleShape bullet = bulletloader();
	vector<RectangleShape> bullets;

	// Create the stars
	vector<CircleShape> stars;
	for (int i = 0; i < 100; i++)
	{
		CircleShape star(rand() % 3);
		star.setFillColor(Color::White);
		star.setPosition(Vector2f(rand() % window.getSize().x, rand() % window.getSize().y));
		stars.push_back(star);
	}

	// Apply the sound for the bullets
	SoundBuffer bullet_sound_buffer = soundloader("blaster-2-81267.wav");
	Sound bullet_sound(bullet_sound_buffer);

	// Main game loop
	while (window.isOpen())
	{
		// Handle events
		Event event{};
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				// Fire a bullet when the space bar is pressed
				if (event.key.code == Keyboard::Space)
				{
					RectangleShape new_bullet = bullet;
					new_bullet.setPosition(
						player.getPosition().x + player.getGlobalBounds().width / 2 - new_bullet.getSize().x / 2,
						player.getPosition().y - new_bullet.getSize().y);
					bullet_sound.play();
					bullets.push_back(new_bullet);
				}
				else if (event.key.code == Keyboard::Escape)
					window.close();
			}
		}

		// Check if player is going out of left edge
		if (Keyboard::isKeyPressed(Keyboard::A) && player.getPosition().x + player.getGlobalBounds().width / 2 > 0)
			player.move(-player_speed, 0);
		// Check if player is going out of right edge
		if (Keyboard::isKeyPressed(Keyboard::D) && player.getPosition().x + (player.getGlobalBounds().width - player.
			getGlobalBounds().width / 2) < window.getSize().x)
			player.move(player_speed, 0);
		// check if player is going out of top edge
		if (Keyboard::isKeyPressed(Keyboard::W) && player.getPosition().y > 0)
		{
			player.move(0, -player_speed);
			for (auto& e : enemies)
				e.move(0, player_speed / 1.5f);
			for (auto& s : stars)
			{
				s.move(0, player_speed / 2);
				if (s.getPosition().y > window.getSize().y)
					s.setPosition(Vector2f(rand() % window.getSize().x, 0));
			}
		}
		// check if player is going out of bottom edge
		if (Keyboard::isKeyPressed(Keyboard::S) && player.getPosition().y + (player.getGlobalBounds().height - player.
			getGlobalBounds().height / 2) < window.getSize().y)
			player.move(0, player_speed);

		// Move the enemy
		for (auto& e : enemies)
			e.move(0, enemy_speed);

		// Move the bullets
		for (auto& b : bullets)
			b.move(0, -10);

		// Move the stars
		for (auto& s : stars)
		{
			s.move(0, enemy_speed / 2);
			if (s.getPosition().y > window.getSize().y)
				s.setPosition(Vector2f(rand() % window.getSize().x, 0));
		}

		// Check for collisions
		for (auto& e : enemies)
		{
			if (e.getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				lives--;
				player.setPosition(window.getSize().x / 2, window.getSize().y - player.getGlobalBounds().height);
				e.setPosition(rand() % window.getSize().x, -100);
			}
			for (auto& b : bullets)
			{
				if (b.getGlobalBounds().intersects(e.getGlobalBounds()))
				{
					score++;
					if (score % 10 == 0)
						enemy_speed += 0.2f;
					e.setPosition(rand() % window.getSize().x, - (rand() % enemy_starting_y));
					b.setPosition(-10, -10);
				}
			}
		}

		// Make sure bullets don't fly off the screen
		bullets.erase(remove_if(begin(bullets), end(bullets), [](const auto& b)
		{
			return b.getPosition().y < 0;
		}), end(bullets));

		// Update the score and lives text
		score_text.setString("Score: " + to_string(score));
		score_text.setPosition(10, 10);
		lives_text.setString("Lives: " + to_string(lives));
		lives_text.setPosition(window.getSize().x - lives_text.getLocalBounds().width - 10, 10);

		// Draw
		draw(window, player, enemies, bullets, stars, score_text, lives_text);

		// Check for game over if lives are 0 or any enemy reaches bottom of screen
		if (lives == 0 || any_of(begin(enemies), end(enemies), [&](const auto& e)
		{
			return e.getPosition().y > window.getSize().y;
		}))
		{
			// Wait for 3 seconds
			sleep(seconds(3));

			// Close the window
			window.close();
		}
	}

	return 0;
}
