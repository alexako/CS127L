
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
#include<windows.h>
string EnterPassword()
{
   string NumAsString="";
   char ch=getch();//h
   while (ch!='\r'){//true
	   cout<<'*';//*****
	   NumAsString+=ch;//"hello"
	   ch=getch();//enter/return
         
   }

   return NumAsString;

}

void main(){
   cout<<"password:";
   string password=EnterPassword();//"hello"

   if(password=="ako")
   {   cout<<"\nprocessing your password";
       
	for(int i=1;i<=5;i++)
		{	Sleep(1000);
			cout<<".";
		}
       //Sleep(5000);
	   system("cls");
	   cout<<"hello Ms.Fuentes";
	
	  } else
   {   cout<<"\nprocessing your password";
       Sleep(1000);
	   cout<<".";
	   Sleep(1000);
	   cout<<".";
	   Sleep(1000);
	   cout<<".";
	   Sleep(1000);
	   cout<<".";
	   Sleep(1000);
	   cout<<".";
       Sleep(5000);
	   system("cls");
	   cout<<"sori";}
	  cout<<endl;


}