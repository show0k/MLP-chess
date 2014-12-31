#include "GraphicEffect.h"

sf::Sprite *_sprite = NULL;
float _time = -1;
float _fact = 0;

void growSprite(){
	sf::Sprite *sprite_temp = _sprite;
	float time_temp = _time;
	float scale_temp = _fact;
	_sprite = NULL;	
	_time = -1;
	_fact = 0;
	
	int nbLoop = (int)(time_temp * 20);
	float scaleIncrement = (scale_temp * sprite_temp->getScale().x- sprite_temp->getScale().x)/nbLoop;

	float newScale;
	for(int i = 0; i<nbLoop;i++){
		newScale = sprite_temp->getScale().x + scaleIncrement;
		sprite_temp->setScale(newScale, newScale);
		usleep(50000);
	}
}

void graphicEffect(string type, sf::Sprite *s, float t, float f){
	bool go = false;
	while(!go){
		if(_fact == 0 && _time == -1 && _sprite == NULL)
			go = true;
	}
	_sprite = s;
	_time = t;
	_fact = f;
}
