#include <iostream>
#include <cstring>
#include "cellType.h"
#include "cellTable.h"
#include <unistd.h>

//Sudoking solving function
bool sudoSolv( cellTable &sudok, int spot_x , int spot_y );

int main()
{
	cellTable table;

	cout << "Enter the file containing the puzzle to solve\n";
	char * myInput;
	myInput = new char [ 255 ];
	cin >> myInput;
	table.fileRead( myInput );

	table.showTable();
	cout << endl;
	sudoSolv( table , 0 , 0 );
	table.showTable();
}

bool sudoSolv( cellTable &sudok, int currentSpot_x , int currentSpot_y )
{
	//Check if any empty spaces exist
	if( !sudok.isFull() )
	{
		//If current cell is 0 and can be modified
		if( sudok.contents[ currentSpot_x ][ currentSpot_y ].val == 0 and 
			sudok.contents[ currentSpot_x ][ currentSpot_y ].user == false )
		{
			//Loop thru all possible values
			for( int i = 1; i < 10; i++ )
				{
					//Check if attempt "fits" in the cell
					if( sudok.checkRow( currentSpot_x , i ) and
						sudok.checkCol( currentSpot_y , i ) and
						sudok.checkBlock( currentSpot_x , currentSpot_y , i ) )
						{
							sudok.contents[ currentSpot_x ][ currentSpot_y ].val = i;

							//sudok.showTable(); cout << endl; usleep( 80000 );

							//Check if end of column
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
								//If the next cell didn't work, try again
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
				//None of the values worked
				return false;
			}

		//If cell cannot be modified, move on to next cell
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
	//Every cell has been filled with a value
	return true;
}
