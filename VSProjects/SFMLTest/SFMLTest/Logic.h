#ifndef LOGIC_H
#define LOGIC_H

#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/GpuPreference.hpp>
#include <SFML/Main.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>


using namespace sf;
using namespace std;

// Function to load the font
Font fontloader(const string& fontfile);

// Function to load the textures
pair<Texture, Texture> textureloader(const string& playerfilename, const string& enemyfilename);

// Function to load the bullets
RectangleShape bulletloader();

// Function to load the sound
SoundBuffer soundloader(const string& soundfilename);

// Function to setup sprites scales and positions and speed
pair<Sprite, Sprite> spritesetup(const Texture& player_texture, const Texture& enemy_texture,
                                 const RenderWindow& window);

// Setup text function
pair<Text, Text> textsetup(const Font& font);

// Draw everything
void draw(RenderWindow& window, const Sprite& player, const vector<Sprite>& enemies,
          const vector<RectangleShape>& bullets, const vector<CircleShape>& stars, const Text& score_text, const Text& lives_text);

#endif // LOGIC_H
