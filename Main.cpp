#include <iostream>
#include <cstring>
#include "cellType.h"
#include "cellTable.h"
#include <unistd.h>

bool sudoSolv( cellTable &sudok, int spot_x , int spot_y );

int main()
{
	cellTable table;
	table.inputVal();
	sudoSolv( table , 0 , 0 );
	table.showTable();
}

bool sudoSolv( cellTable &sudok, int currentSpot_x , int currentSpot_y )
{
	if( !sudok.isFull() )
	{
		if( sudok.contents[ currentSpot_x ][ currentSpot_y ].val == 0 and 
			sudok.contents[ currentSpot_x ][ currentSpot_y ].user == false )
		{
			for( int i = 1; i < 10; i++ )
				{
					if( sudok.checkRow( currentSpot_x , i ) and
						sudok.checkCol( currentSpot_y , i ) and
						sudok.checkBlock( currentSpot_x , currentSpot_y , i ) )
						{
							sudok.contents[ currentSpot_x ][ currentSpot_y ].val = i;

							//sudok.showTable(); cout << endl; usleep( 80000 );

							if( currentSpot_x == 8 )
							{

								if( sudoSolv( sudok , 0 , currentSpot_y + 1 )  == false )
								{
									sudok.contents[ currentSpot_x ][ currentSpot_y ].val = 0;
								}

								else
		                        {
									return true;
		                        }


                        	}

							else if( currentSpot_x < 8 )
							{
								if( sudoSolv( sudok , currentSpot_x + 1 , currentSpot_y )  == false )
								{
                            	 	sudok.contents[ currentSpot_x ][ currentSpot_y ].val = 0;
                            	}


								else
								{
									return true;
								}

							}
						}
                }
				return false;
			}

		else if( sudok.contents[ currentSpot_x ][ currentSpot_y ].user == true )
		{
			if( currentSpot_x < 8 )
			{
				if( sudoSolv( sudok , currentSpot_x + 1 , currentSpot_y ) == false )
				{
					return false;
				}
			}

			else if( currentSpot_x == 8 )
			{
				if( sudoSolv( sudok , 0 , currentSpot_y + 1 ) == false )
				{
					return false;
				}
			}
		}
	}
	return true;
}
