#ifndef KILLTRACK_H_INCLUDED 
#define KILLTRACK_H_INCLUDED 

struct KillTrack 
{
	char name[50] ;
	int kill;
	
	KillTrack(char* setName, int setKill )
	{
		strcpy(name,setName);
		kill=setKill;
	}
	
	KillTrack()
	{
	}
}kill_track;


// for custom number showing
void showNumber(int x, int y, int size, int number)
{
	digit_x = x + 4 * size;
	digit_y = y;

	for (int i = 0; i < 5; i++)
	{
		if (number > 0)
		{
			digit[i] = number % 10;
			number = number / 10;
		}
		else
		{
			digit[i] = 0;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		iShowImage(digit_x - i * size, digit_y, size, 1.4*size, digit_image[digit[i]]);
	}
}


//for showing kills 


void showKillTracks()
{
	FILE *fp = fopen("kill_tracks.bin", "rb");

	if (fp == NULL)
	{
	}

	else
	{
		KillTrack kill_track_temp;
		char kill_string[10];

		for (int text_y = 475; fread(&kill_track_temp, sizeof(struct KillTrack), 1, fp) == 1; text_y -= 65)
		{
		
			sprintf(kill_string, "%d", kill_track_temp.kill);

			iSetColor(255, 255, 255);
			iText(280, text_y, kill_track_temp.name, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(1050, text_y, kill_string, GLUT_BITMAP_TIMES_ROMAN_24);
		}

		fclose(fp);
	}
}






void inputName(unsigned char key)
{
	if (game_over && soldier_rank >= 1 && soldier_rank <= 5)
	{
		if (field_active && name_index < 33)
		{
			if (key == '\b')
			{
				if (name_index > 0)
				{
					kill_track.name[--name_index] = NULL;
				}
			}
			else if (name_index < 32 && key != '\r' && (key >= 'A' && key <= 'Z' || key >= 'a' && key <= 'z' || key >= '0' && key <= '9' || key == ' '))
			{
				kill_track.name[name_index++] = key;
			}
		}
	}
}




void setSoldierName()
{
	if (field_active)
	{
		iSetColor(255, 255, 255);
		iRectangle(518, 289, 486, 58);
		iText(570, 310, kill_track.name, GLUT_BITMAP_TIMES_ROMAN_24); //Gets the value from void inputName() function.
	
	}
	else
	{
		iSetColor(255, 255, 255);
		iText(570, 310, kill_track.name, GLUT_BITMAP_TIMES_ROMAN_24);
	}
}






void activateTextBox(int mx, int my)
{
	if (game_over && soldier_rank >= 1 && soldier_rank <= 5)
	{
		if (mx >= 518 && mx <= 1004 && my >= 289 && my <= 347)
		{
			field_active = true;
		
		}
		else
		{
			field_active = false;
		}
	}
}









void saveKill()
{
	FILE *fp = fopen("kill_tracks.bin", "rb");

	if (fp == NULL)
	{
		fp = fopen("kill_tracks.bin", "wb");
		fclose(fp);

		fp = fopen("kill_tracks.bin", "rb");
	}

	KillTrack kill_track_temp[6];
	KillTrack kill_track_temp2;

	int element_index = 0;

	while (fread(&kill_track_temp2, sizeof(struct KillTrack), 1, fp) == 1)
	{
		kill_track_temp[element_index] = kill_track_temp2;
		element_index++;
	}

	fclose(fp);

	if (element_index > 4)
	{
		element_index = 4;
	}

	/*Shifting array elements to right to make space for the new entry.*/
	for (int i = element_index; i >= soldier_rank; i--)
	{
		kill_track_temp[i] = kill_track_temp[i - 1];
	}

	/*
	
	
	
	
	
	
	
	
	*/ 
	
	
	
	
	
	
	
	kill_track_temp[soldier_rank - 1] = kill_track;

	

	fp = fopen("kill_tracks.bin", "wb");

	if (fp == NULL)
	{
	}

	else
	{
		fwrite(&kill_track_temp, sizeof(struct KillTrack), (element_index + 1), fp);
	}

	fclose(fp);
}




// the following code variable have to be rechecked


void moveIcon()
{
	static int recall = 0;

	if (recall % 4 == 0)
	{
		icon_index++;

		if (icon_index > 1)
		{
			icon_index = 0;
		}
	}

	recall++;

	if (recall >= 20)
	{
		recall = 0;
	}
}

#endif

