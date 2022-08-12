#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED




/* https://docs.microsoft.com/en-us/previous-versions/dd743680(v=vs.85) 
*/

void controlMusic(bool state ) 
{
	if(!mute)
	{
		if(state)
		{ 
			if(menu_option >= 0 && menu_option <= 5)
			{
				PlaySound("music\\intro.wav", NULL, SND_LOOP | SND_ASYNC); //Julius Dreisig & Zeus X Crona - Invisible [NCS Release]
			}

			else if (game_over)
			{
				PlaySound("music\\game_over.wav", NULL, SND_LOOP | SND_ASYNC); //Unknown Brain - Inspiration (feat. Aviella) [NCS Release]
			}

			else
			{
				PlaySound("music\\ingame.wav", NULL, SND_LOOP | SND_ASYNC); //tobu_turn it up by aquas 
			}
		}

		else
		{
			PlaySound(0, 0, 0);
		}
	}
}



#endif
