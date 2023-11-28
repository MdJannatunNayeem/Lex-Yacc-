#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<vector>

using namespace std;

class QuizeGame
{
private:

public:
    string name;
    int age;
    int corrects;

    void Display();
    void Menu();
    void Start_Game();
    void View_Score();
    void Delete();
    void Question();


};

void QuizeGame:: Display()
{

        cout<<"\n\n\n\n\n\n";
		cout<<"\n\t   +-------+                          _______       _______                             ";
		cout<<"\n\t   |       |      |         |            |                /                              ";
		cout<<"\n\t   |       |      |         |            |               /                               ";
		cout<<"\n\t   |       |      |         |            |              /                                ";
		cout<<"\n\t   |   \\   |      |         |            |             /                                 ";
		cout<<"\n\t   |    \\  |      |         |            |            /                                  ";
		cout<<"\n\t   +-----\\-+      |_________|         ___|___        /_______                          ";
		cout<<"\n\n\n\n\n\n";
		cout<<"\n\t   +-------+       /\\       |\\            /| +-------                  ";
		cout<<"\n\t   |       |      /  \\      | \\          / | |                          ";
		cout<<"\n\t   |             /    \\     |  \\        /  | |                          ";
		cout<<"\n\t   |            /------\\    |   \\      /   | +-------                  ";
		cout<<"\n\t   |   ----|   /        \\   |    \\    /    | |                         ";
		cout<<"\n\t   |       |  /          \\  |     \\  /     | |                        ";
		cout<<"\n\t   +-------+ /            \\ |      \\/      | +-------                ";


		cout<<"\n\n\n\n\n\n\t\t\t   PRESS ENTER TO CONTINUE.....     ";


		system("pause");
		system("cls");

}

void QuizeGame::Menu()
{

        menustart:
            system("cls");

        int choice;
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t|                  Welcome to Quiz Game                          |\n";
        cout<<"\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t-------------------       MENU        -----------------------------------\n\n";
        cout<<"\t\t\t\t\t1.Start Game"<<endl;
        cout<<"\t\t\t\t\t2.View Score"<<endl;
        cout<<"\t\t\t\t\t3.Delete Score"<<endl;
        cout<<"\t\t\t\t\t4.Exit"<<endl;
        cout<<"\n\t\t\t\t\tEnter your choice (1/2/3/4) :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        Start_Game();
                        break;
                case 2:
                        View_Score();
                        break;
//                case 3:
//                        Delete();
//                        break;
                case 4:

                        cout<<"\n\t\t\t\t\tThanks for using this program.\n\t\t\t\t\tThis program is created by Team Antivirus.\n\n";

                        break;
                default:
                        system("cls");
                        cout<<"\t\t\t\t\tYou've made a mistake , Try again..\n"<<endl;
                        cin.get();
                        cin.get();
                        goto menustart;
        }


}

void QuizeGame::Start_Game()
{
    system("cls");
        cout<<"\t\t\t--------------------------------------------------------------------"<<endl;
        cout<<"\t\t\t|                    Starting Quiz Game.....                             |\n";
        cout<<"\t\t\t--------------------------------------------------------------------"<<endl;

        cout<<"\n\n\t\t\t 1)Enter Your Name:";
        cin>>name;
        cout<<"\n\t\t\t 2)Enter Your Age:";
        cin>>age;

        ofstream file;
        file.open("quiz.txt",ios::app);
        file<<name<<" "<<age<<endl;

        cin.get();
        file.close();

         string Respond;
         cout << "Are you ready to take the quiz " << name << "? yes/no" << endl;
         cin >> Respond;
         if (Respond == "yes"||Respond == "y"||Respond == "Y")
        {
            cout << "Good Luck!";
            Question();
        }
        else
        {
            cout << "Okay Good Bye!";
            Menu();
        }
}
void QuizeGame::Question()
{
     system("cls");
        cout<<"\t\t\t--------------------------------------------------------------------"<<endl;
        cout<<"\t\t\t|                    Quiz Game                                |\n";
        cout<<"\t\t\t--------------------------------------------------------------------"<<endl;



        string questions[4] = {"1.What year was C++ created?\n",
                                "2.Who invented C++?\n",
                                "3.What is the predescessor of C++?\n",
                                "4.Is the Eart flat?\n"};

        string answers[][4] = {{"1940\t", "1985\t", "2001\t", "2003\t"},
                                {"Bjarne Stroustrup\t", "Frank Einstein\t", "Michael Jordan\t", "Mark Zuckerburg\t"},
                                {"C\t", "C#\t", "C++\t", "F++\t"},
                                {"Yes\t", "No\t", "Sometimes\t", "What's Earth?\t"}};


        char answerKey[] = {'B', 'A', 'C', 'B'};
        corrects = 0;

        int size = sizeof(questions) / sizeof(questions[0]);
        char answer;

        for (int i = 0; i < size; i++)
        {
            cout << questions[i];
            for (int j = 0; j < size; j++)
            {
                cout << answers[i][j];
            }
            cin >> answer;
            answer = toupper(answer);
            if (answerKey[i] == answer)
            {
                corrects++;
            }
        }

        cout << "You answered " << corrects << " questions correctly"<<endl;

        ofstream file;
        file.open("quiz.txt",ios::app);

        file<<corrects<<endl;


        cin.get();
        cin.get();
        file.close();

        Menu();

}


void QuizeGame::View_Score()
{

    system("cls");
    fstream file;
    int total=1;

        cout<<"\t\t\t--------------------------------------------------------------------"<<endl;
        cout<<"\t\t\t|                          Score                                |\n";
        cout<<"\t\t\t--------------------------------------------------------------------"<<endl;


    file.open("quiz.txt", ios::in);
    if (!file)
    {
        /* code */
        cout << "\n\t\t\tNo Data Is Present...";
        file.close();

    }
    else
    {
        file >> name>> age;
        file>>corrects;

        while (!file.eof())
        {

           cout<<"\n\n\t\t\t Serial NO:" << total++;


           cout<<"\n\n\t\t\t 1)Name: "<< name;
           cout<<"\n\t\t\t 2)Age: "<<age;

           file>> name>>age;

           cout<<"\n\t\t\t 3)Total Result: "<<corrects;
            file>>corrects;

            }
    }
       if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is Present..."<<endl;

        }

    file.close();


    cin.get();
    cin.get();
    Menu();
}

int main()
{
    QuizeGame obj;

    obj.Display();
    obj.Menu();

    return 0;
}
