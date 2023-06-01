#include <iostream>
#include <math.h>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;
int main()

{
    // * змінні
    const double pi = atan(1.0) * 4;
    double X = 0, Y = 0, steps = 0;

    int actions = 0, direction = 0, language = 0, engMenu = 0, ukrMenu = 0, exit = 0;

    // * вибір мови
    do{
        cout << "Which language? " << endl
             << "1. Ukrainian" << endl
             << "2. English" << endl;
        cout << "Your language: ";
        cin >> language;

        switch (language)
        {
            // * українське меню
        case 1:
            cout << "Що ви хочете зробити? " << endl
                 << "1. Робота з текстовим файлом" << endl
                 << "2. Робота з консоллю" << endl
                 << "3. Перегляд інструкції" << endl
                 << "4. Зміна зовнішнього вигляду консолі" << endl
                 << "5. Вихід з програми" << endl;
            cout << "Вибрано пункт: ";
            cin >> ukrMenu;

            switch (ukrMenu)
            {
                // * український файл
                case 1:
                {
                    ifstream cin("mapa.txt");   // відкриваю файл на читання
                    ofstream cout("skarb.txt"); // відкриваю файл на вивід

                    if (!cin.is_open())
                    {
                        cerr << "You don't have «mapa.txt»!" << endl;
                        return 1;
                    }
                    // якщо файлу "мапа.тхт" не існує, то видає помилку і закриває прогу
                    if (!cout.is_open())
                    {
                        cerr << "You don't have «scarb.txt»!" << endl;
                        return 1;
                    }
                    // якщо файлу "скарб.тхт" не існує, то видає помилку і закриває прогу

                    cin >> actions;

                    for (int i = 1; i <= actions; i++)
                    {
                        cin >> direction >> steps;

                        X = X + sin(pi / 4 * (direction - 1)) * steps;

                        Y = Y + cos(pi / 4 * (direction - 1)) * steps;
                    }

                    if (abs(X) < 0.001)
                        X = 0;
                    if (abs(Y) < 0.001)
                        Y = 0;

                    cout.precision(3); // amount of numbers after the comma
                    cout << fixed << "Скарб знаходиться за координатами: " << endl
                        << X << " " << Y << endl;

                    cin.close();
                    cout.close();
                    cout << "Координату обраховано, закриваю програму..." << endl;

                    break;
                }

            // * українська консолька
                case 2:
                {
                    cout << "Введіть кількість дій: ";
                    cin >> actions;
                    cout << "Кількість дій: " << actions << endl;

                    for (int i = 1; i <= actions; i++)
                    {
                        cout << "Введіть напрямок і кількість кроків: ";
                        cin >> direction >> steps;

                        X = X + sin(pi / 4 * (direction - 1)) * steps;
                        Y = Y + cos(pi / 4 * (direction - 1)) * steps;
                    }

                    if (abs(X) < 0.001)
                        X = 0;
                    if (abs(Y) < 0.001)
                        Y = 0;

                    cout.precision(4);
                    cout << "Скарб знаходиться за координатами: " << X << " " << Y << endl;
                    break;
                }
            // * українська інструкція
            // ! хотілось би зробити якісь бордери для нормальної читабельності тексту
            // ? наче зробив більш-менш
                case 3:
                {
                    cout << "Інструкція:" << endl
                        << "Знайти закопаний піратами скарб просто: все, що для цього потрібно – це карта. Як відомо, пірати зазвичай малюють карти від руки і описують алгоритм знаходження скаобу так:\n«Встаньте спиною близько самотньої пальми. Пройдіть тридцять кроків у бік лісу, потім сімнадцять кроків у бік озера, ..., нарешті десять кроків в бік великого кругляка. Скарб знаходиться під ним».\nВелика частина таких вказівок просто зводиться до проходження певної кількості кроків в одному з восьми напрямків (1 - північ, 2 - північний схід, 3 - схід, 4 - південний схід, 5 - південь, 6 - південний захід, 7 - захід, 8 - північний захід). Довжина кроку в будь-якому напрямку дорівнює 1." << endl
                        << "\nПри виборі відповідного пункту меню ви зможете: " << endl
                        << "\n1. Працювати з файлами. Програма зчитує дані з файлу mapa.txt. У нього ви маєте завчасно ввести необхідні для правильної роботи програми дані у такому форматі:\nУ перший рядок вводиться кількість вказівок (число від 1 до 40), далі у певну кількість рядків, відповідно кількості вказівок, через Enter вказується напрям руху (цифру від 1 до 8) та кількість кроків у цьому напрямку (від 1 до 1000). Вказівки мають вводитись у форматі «напрям_руху [пробіл] кількість_кроків». У файлі skarb.txt ви побачите відповідь – кінцеву координату скарбу." << endl
                        << "\n2. Робота з консоллю. Працюючи за допомогою консолі, відповідно до тексту-запиту, ви вводите необхідні дані (вказівки – від 1 до 40, напрям руху – цифру від 1 до 8, кількість кроків у цьому напрямку – від 1 до 1000). Формат вводу даних – «напрям_руху [пробіл] кількість_кроків». Кінцева координата теж виводиться у консоль." << endl
                        << "\n3. Перегляд інструкції до програми. При виборі цього пункту меню ви маєте можливість прочитати інтструкцію, яка пояснить вам як правильно користуватись програмою." << endl
                        << "\n4. Зміна зовнішнього вигляду консолі. Ви маєте можливість змінити зовнішній вигляд консолі: колір фону (обираєте потрібний номер з списку), колір шрифту (обираєте потрібний номер з списку), розмір шрифту." << endl
                        << "\n5. Вихід з програми. При виборі даного пункту здійснюється вихід з програми" << endl;
                    break;
                }
                case 5:
                {
                    cout << "Закриваю програму..." << endl;
                    //? Краще зразу закривати чи через паузу?
                    system("PAUSE");
                    return 0;
                }
                default:
                    cout << "Просто напишіть 1, 2, 3, 4 чи 5!" << endl;
            }
            system("PAUSE");
            return 0;

        // * англійське меню
        case 2:
        {
            cout << "Do you want to work with text file or with console? " << endl
                 << "1. Work with files" << endl
                 << "2. Work with the console" << endl
                 << "3. View the instructions for the program" << endl
                 << "4. Changing the appearance of the console" << endl
                 << "5. Exit the program" << endl;
            cin >> engMenu;

                switch (engMenu)
                {
                // * англ файл
                case 1:
                {
                    ifstream cin("mapa.txt");
                    ofstream cout("skarb.txt");

                    if (!cin.is_open())
                    {
                        cerr << "You don't have «mapa.txt»!" << endl;
                        return 1;
                    }
                    // якщо файлу "мапа.тхт" не існує, то видає помилку і закриває прогу
                    if (!cout.is_open())
                    {
                        cerr << "You don't have «scarb.txt»!" << endl;
                        return 1;
                    }
                    // якщо файлу "скарб.тхт" не існує, то видає помилку і закриває прогу

                    cin >> actions;

                    for (int i = 1; i <= actions; i++)
                    {
                        cin >> direction >> steps;

                        X = X + sin(pi / 4 * (direction - 1)) * steps;

                        Y = Y + cos(pi / 4 * (direction - 1)) * steps;
                    }

                    if (abs(X) < 0.001)
                        X = 0;
                    if (abs(Y) < 0.001)
                        Y = 0;

                    cout.precision(3); // amount of numbers after the comma
                    cout << fixed << "Coordinates of treasure: " << endl
                        << X << " " << Y << endl;

                    cin.close();
                    cout.close();
                    cout << "The coordinate is calculated, closing the program..." << endl;

                    break;
                }
                // * англ консолька
                case 2:
                {
                    setlocale(LC_ALL, "English");
                    cout << "Enter amount of actions: ";
                    cin >> actions;
                    cout << "Amount of actions: " << actions << endl;

                    for (int i = 1; i <= actions; i++)
                    {
                        cout << "Enter direction and steps: ";
                        cin >> direction >> steps;

                        X = X + sin(pi / 4 * (direction - 1)) * steps;
                        Y = Y + cos(pi / 4 * (direction - 1)) * steps;
                    }

                    if (abs(X) < 0.001)
                        X = 0;
                    if (abs(Y) < 0.001)
                        Y = 0;

                    cout.precision(4);
                    cout << "Treasure: " << X << " " << Y << endl;
                    break;
                }
                // * англ інструкція
                case 3:
                {
                    cout << "Instruction: " << endl
                        << "Finding treasure buried by pirates is simple: all you need for this is a map. As you know, pirates usually draw maps by hand and describe the algorithm for finding a treasure as follows:\n«Stand with your back near a lonely palm tree. Walk thirty paces towards the forest, then seventeen steps towards the lake, ..., finally ten steps towards the big log. The treasure is under it».\nMost of these instructions simply boil down to taking a certain number of steps in one of eight directions (1 - north, 2 - north-east, 3 - east, 4 - southeast, 5 - south, 6 - southwest, 7 - west, 8 - northwest). The length of a step in any direction is equal to 1." << endl
                        << "\nBy choosing the appropriate menu item, you can: " << endl
                        << "\n1. Work with files. The program reads data from the mapa.txt file. In it, you must enter in advance the data necessary for the correct operation of the program in the following format:\nThe number of instructions is entered in the first line (a number from 1 to 40), then in a certain number of lines, according to the number of instructions, the direction of movement (a number from 1 to 8) and the number of steps in this direction (from 1 to 1000) are indicated through Enter. Directions should be entered in the format «direction_of_movement [space] number_of_steps». In the file skarb.txt you will see the answer - the final coordinate of the treasure." << endl
                        << "\n2. Work with the console. Working with the console, in accordance with the text-request, you enter the necessary data (directions - from 1 to 40, direction of movement - a number from 1 to 8, number of steps in this direction - from 1 to 1000). The data input format is «direction_of_movement [space] number_of_steps». The final coordinate is also output to the console." << endl
                        << "\n3. View the instructions for the program. When choosing this menu item, you have the opportunity to read an instruction that will explain to you how to use the program correctly." << endl
                        << "\n4. Changing the appearance of the console. You can change the appearance of the console: background color (select the desired number from the list), font color (select the desired number from the list), font size." << endl
                        << "\n5. Exit the program. Selecting this item exits the program" << endl;
                    break;
                }
                case 5:
                {
                    cout << "Closing the program..." << endl;
                    //? Краще зразу закривати чи через паузу?
                    system("PAUSE");
                    return 0;
                }
                default:
                    cout << "Just print 1, 2, 3, 4 or 5!" << endl;
                }
            break;
        }
        default:
            cout << "Just print 1 or 2!" << endl;
        }
    } while (language != 2);
    system("PAUSE");
    return 0;
}