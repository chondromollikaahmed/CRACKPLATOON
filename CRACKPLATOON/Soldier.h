#ifndef SOLDIER_H_INCLUDED 
#define SOLDIER_H_INCLUDED 

struct Soldier 
{
	int x , y ;
	int dim_x, dim_y ; // not the image dimension 
	int extDim_x , extDim_y ;
	int condition , condition_changer ;
	int kill , health ;  
	bool visible ;
	

	
	/* this part for image adding  
	*/
	
	
	int image_idle[20], image_idleback[20], image_attack[20], image_attackback[20], image_jumping[20], image_jumpingback[20], image_plane[20];

	
	
	
	Soldier (int cx , int cy , int dx, int dy ,int edx , int edy ) 
	{
		x=cx;
		y=cy;
		dim_x=dx;
		dim_y=dy;
		extDim_x=edx;
		extDim_y=edy ; 
		}
		
		Soldier (int cx , int cy , int dx, int dy ,int edx , int edy, int con, int cch, int k, int h,bool v  ) 
	{ 
		//for level one 
		x=cx;
		y=cy;
		dim_x=dx;
		dim_y=dy;
		extDim_x=edx;
		extDim_y=edy ; 
		condition = con ; 
		condition_changer = cch ; 
		kill= k ;
		health = h ; 
		visible= v; 
		}
		
		Soldier (int cx , int cy , int dx, int dy ,int edx , int edy,bool v  ) 
	{ 
		
		//for level two 
		x=cx;
		y=cy;
		dim_x=dx;
		dim_y=dy;
		extDim_x=edx;
		extDim_y=edy ; 
		visible = v ; 
		} 
	}intro(160,580,100,180,20,20),soldier(160, 68, 90, 140, 35, 8, 0, 0, 0, 100,true), helicopter(160, 520, 152, 122, 24, 25, true);// instance declaration ; 
		
#endif 

		