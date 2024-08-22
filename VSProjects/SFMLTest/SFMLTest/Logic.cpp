#include "Logic.h"

// Function to load the font
Font fontloader(const string& fontfile)
{
	// Load the font
	Font font;
	if (!font.loadFromFile(fontfile))
	{
		cerr << "Error loading font\n";
		exit(1);
	}
	return font;
}

// Function to load the textures
pair<Texture, Texture> textureloader(const string& playerfilename, const string& enemyfilename)
{
	// Load the player and enemy
	Texture player_texture, enemy_texture;
	if (!player_texture.loadFromFile(playerfilename) || !enemy_texture.loadFromFile(enemyfilename))
	{
		cerr << "Error loading textures\n";
		exit(1);
	}
	return make_pair(player_texture, enemy_texture);
}

// Function to load the bullets
RectangleShape bulletloader()
{
	// Load the bullet
	RectangleShape bullet(Vector2f(5, 20));
	bullet.setFillColor(Color::Red);
	return bullet;
}

// Function to load the sound
SoundBuffer soundloader(const string& soundfilename)
{
	// Load the sound
	SoundBuffer sound_buffer;
	if (!sound_buffer.loadFromFile(soundfilename))
	{
		cerr << "Error loading sounds\n";
		exit(1);
	}
	return sound_buffer;
}

// Function to setup sprites scales and positions
pair<Sprite, Sprite> spritesetup(const Texture& player_texture, const Texture& enemy_texture,
                                 const RenderWindow& window)
{
	// Set up the player and enemy
	Sprite player(player_texture), enemy(enemy_texture);
	player.setScale(0.25f, 0.25f); // optional: adjust the scale of the sprite
	enemy.setScale(0.5f, 0.5f); // optional: adjust the scale of the sprite
	player.setPosition(window.getSize().x / static_cast<float>(2),
	                   window.getSize().y - player.getGlobalBounds().height);
	return make_pair(player, enemy);
}

// Setup text function
pair<Text, Text> textsetup(const Font& font)
{
	// Set up the text for the score and lives
	Text score_text("", font, 30);
	Text lives_text("", font, 30);
	return make_pair(score_text, lives_text);
}

// Draw everything
void draw(RenderWindow& window, const Sprite& player, const vector<Sprite>& enemies,
          const vector<RectangleShape>& bullets, const vector<CircleShape>& stars, const Text& score_text,
          const Text& lives_text)
{
	window.clear();
	// Draw the stars
	for (auto& s : stars)
		window.draw(s);
	// Draw the player
	window.draw(player);
	// Draw the enemy
	for (const auto& e : enemies)
		window.draw(e);
	// Draw the bullets
	for (const auto& b : bullets)
		window.draw(b);
	// Draw the score and lives
	window.draw(score_text);
	window.draw(lives_text);
	window.display();
}
