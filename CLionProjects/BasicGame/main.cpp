#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <SFML/Config.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

//VECTOR MATH
//LENGTH OF VECTOR
//|V| = sqrt(pow(Vx,2) + pow(Vy,2));
//U = V/|V| = (Vx, Vy)|V| / sqrt (pow(Vx,2) + pow(Vy,2));

using namespace sf;

class Bullet
{
public:
    Sprite shape;

    Bullet(Texture* texture, Vector2f pos)
    {
        shape.setTexture(*texture);
        shape.setScale(0.07f, 0.07f);
        shape.setPosition(pos);
    }
};

class Player
{
public:
    Sprite shape;
    Texture* texture;
    int HP;
    int HPMax;
    std::vector<Bullet> bullets;

    Player(Texture* texture)
    {
        HPMax = 10;
        HP = HPMax;
        this->texture = texture;
        shape.setTexture(*texture);
        shape.setScale(0.1f, 0.1f);
    }
};

class Enemy
{
public:
    Sprite shape;
    int HP;
    int HPMax;

    Enemy(Texture* texture, Vector2u windowSize)
    {
        HPMax = rand() % 3 + 1;
        HP = HPMax;
        shape.setTexture(*texture);
        shape.setScale(0.1f, 0.1f);
        shape.setPosition(windowSize.x - shape.getGlobalBounds().width, rand() % static_cast<int>(windowSize.y - shape.getGlobalBounds().height));
    }
};

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    RenderWindow window(VideoMode(800, 600), "Spaceship action!", Style::Default);
    window.setFramerateLimit(60);

    //Init text
    Font font;
    font.loadFromFile("Fonts/FontFile.ttf");

    //Init texture
    Texture playerTex;
    playerTex.loadFromFile("Textures/ship.png");

    Texture enemyTex;
    enemyTex.loadFromFile("Textures/enemy.png");

    Texture bulletTex;
    bulletTex.loadFromFile("Textures/missileTex01.png");

    //UI init
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(Color::White);
    scoreText.setPosition(10.f, 10.f);

    Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(30);
    gameOverText.setFillColor(Color::Red);
    gameOverText.setPosition(100.f, window.getSize().y / 2);
    gameOverText.setString("GAME OVER!");

    //Player init
    int score = 0;
    Player player(&playerTex);
    int shootTimer = 20;
    Text hpText;
    hpText.setFont(font);
    hpText.setCharacterSize(12);
    hpText.setFillColor(Color::White);

    //Enemy init
    int enemySpawnTimer = 0;
    std::vector<Enemy> enemies;
    Text eHpText;
    eHpText.setFont(font);
    eHpText.setCharacterSize(12);
    eHpText.setFillColor(Color::White);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        // Code for when the player is still alive
        if (player.HP > 0)
        {
            // Player movement
            if (Keyboard::isKeyPressed(Keyboard::W))
                player.shape.move(0.f, -10.f);
            if (Keyboard::isKeyPressed(Keyboard::A))
                player.shape.move(-10.f, 0.f);
            if (Keyboard::isKeyPressed(Keyboard::S))
                player.shape.move(0.f, 10.f);
            if (Keyboard::isKeyPressed(Keyboard::D))
                player.shape.move(10.f, 0.f);

            // Update the HP text position and value
            hpText.setPosition(player.shape.getPosition().x,
                               player.shape.getPosition().y - hpText.getGlobalBounds().height);
            hpText.setString(std::to_string(player.HP) + "/" + std::to_string(player.HPMax));

            // Collision with window
            if (player.shape.getPosition().x <= 0) // Left of scene
                player.shape.setPosition(0.f, player.shape.getPosition().y);
            if (player.shape.getPosition().x >=
                window.getSize().x - player.shape.getGlobalBounds().width) // Right of scene
                player.shape.setPosition(window.getSize().x - player.shape.getGlobalBounds().width,
                                         player.shape.getPosition().y);
            if (player.shape.getPosition().y <= 0) // Top of scene
                player.shape.setPosition(player.shape.getPosition().x, 0.f);
            if (player.shape.getPosition().y >=
                window.getSize().y - player.shape.getGlobalBounds().height) // Bottom of scene
                player.shape.setPosition(player.shape.getPosition().x,
                                         window.getSize().y - player.shape.getGlobalBounds().height);

            // Shooting
            if (shootTimer < 20)
                shootTimer++;
            if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 20) {
                // Create a new bullet and add it to the vector of bullets
                bullets.push_back(Bullet(&bulletTex, player.shape.getPosition()));
                shootTimer = 0; // Reset the shoot timer
            }

            // Update the bullets
            for (size_t i = 0; i < bullets.size(); i++) {
                bullets[i].shape.move(30.f, 0.f);

                // If the bullet is out of the window, delete it
                if (bullets[i].shape.getPosition().x > window.getSize().x) {
                    bullets.erase(bullets.begin() + i);
                    break;
                }

                // Check for collision with enemies
                for (size_t k = 0; k < enemies.size(); k++) {
                    if (bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds())) {
                        if (enemies[k].HP > 1)
                            enemies[k].HP--;
                        else {
                            enemies.erase(enemies.begin() + k);
                            score += 10;
                        }
                        bullets.erase(bullets.begin() + i);
                        break;
                    }
                }
            }

            // Spawn enemies
            if (enemySpawnTimer < 30)
                enemySpawnTimer++;
            if (enemySpawnTimer >= 30) {
                enemies.push_back(Enemy(&enemyTex, window.getSize()));
                enemySpawnTimer = 0;
            }

            // Update the enemies
            for (size_t i = 0; i < enemies.size(); i++) {
                enemies[i].shape.move(-2.f, 0.f);

                // If the enemy is out of the window, delete it
                if (enemies[i].shape.getPosition().x + enemies[i].shape.getGlobalBounds().width < 0) {
                    enemies.erase(enemies.begin() + i);
                    break;
                }

                // Update the enemy HP text
                eHpText.setPosition(enemies[i].shape.getPosition().x,
                                    enemies[i].shape.getPosition().y - eHpText.getGlobalBounds().height);
                eHpText.setString(std::to_string(enemies[i].HP) + "/" + std::to_string(enemies[i].HPMax));

                // Check for collision with the player
                if (enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds())) {
                    if (player.HP > 1)
                        player.HP--;
                    else
                        player.HP = 0;
                    enemies.erase(enemies.begin() + i);
                    break;
                }
            }
        }

        // Update the score text
        scoreText.setString("Score: " + std::to_string(score));

        // Clear the window
        window.clear(Color::Black);

        // Draw the player
        window.draw(player.shape);
        window.draw(hpText);

        // Draw the bullets
        for (size_t i = 0; i < bullets.size(); i++)
            window.draw(bullets[i].shape);

        // Draw the enemies
        for (size_t i = 0; i < enemies.size(); i++) {
            window.draw(enemies[i].shape);
            window.draw(eHpText);
        }

        // Draw the score text
        window.draw(scoreText);

        // Draw the game over text if the player is dead
        if (player.HP <= 0)
            window.draw(gameOverText);

        // Display the window
        window.display();
    }

    return 0;
}