#ifndef INRANGE_H_INCLUDED
#define INRANGE_H_INCLUDED 

#include <iostream>
using namespace std;

/* function for checking if enemy is in range or not */
/*
bool current_dam = false ;
bool last_dam = false ;

bool checkRange (int obj1_x, int obj1_y,int dim1_x,int dim1_y,int obj2_x,int obj2_y,int dim2_x, int dim2_y)
{
	
	
	if ( obj1_x >= obj2_x && obj1_x<=obj2_x + dim2_x || obj1_x + dim1_x >= obj2_x && obj1_x +dim1_x <= obj2_x + dim2_x || obj1_x <= obj2_x && obj1_x + dim1_x >= obj2_x + dim2_x )
	    {
		   if (obj1_y>= obj2_y && obj1_y<=obj2_y + dim2_y || obj1_y +dim2_y >= obj2_y && obj1_y + dim1_y <= obj2_y + dim2_y || obj1_y<= obj2_y && obj1_y + dim1_y >= obj2_y + dim2_y ) 
		          {
			           current_dam=true ; 
			        }
			} 
	 if (!last_dam && current_dam )
	{
		last_dam= current_dam ;
		return true ;
	}
	else if ( last_dam && ! current_dam ) 
	{
		last_dam=current_dam ;
		return false ; 
	}
	
	else 
	{
		return false ;
	}
}  */



bool current_col = false;
bool last_col = false;

bool checkRange(int obj1_x, int obj1_y, int dim1_x, int dim1_y, int obj2_x, int obj2_y, int dim2_x, int dim2_y)
{
	current_col = (obj1_x >= obj2_x && obj1_x <= obj2_x + dim2_x || obj1_x + dim1_x >= obj2_x && obj1_x + dim1_x <= obj2_x + dim2_x || obj1_x <= obj2_x && obj1_x + dim1_x >= obj2_x + dim2_x) &&
		(obj1_y >= obj2_y && obj1_y <= obj2_y + dim2_y || obj1_y + dim1_y >= obj2_y && obj1_y + dim1_y <= obj2_y + dim2_y || obj1_y <= obj2_y && obj1_y + dim1_y >= obj2_y + dim2_y);

	if (!last_col && current_col)
	{
		cout << "True!" << endl;
		last_col = current_col;
		return true;
	}

	/*else if (last_col && current_col)
	{
		return false;
	}*/

	else if (last_col && !current_col)
	{
		cout << "False!" << endl;
		last_col = current_col;
		return false;
	}

	/*else if (!last_col && !current_col)
	{
		return false;
	}*/

	else
	{
		cout << obj1_x << " " << obj1_y << " " << dim1_x << " " << dim1_y << " " << obj2_x << " " << obj2_y << " " << dim2_x << " " << dim2_y << endl;
		return false;
	}
}
#endif //INRANGE_H_INCLUDED