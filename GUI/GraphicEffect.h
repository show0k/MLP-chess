/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <unistd.h>

using namespace std;

void growSprite(); 
void graphicEffect(string type, sf::Sprite *s, float t, float f);
