#include <iostream>

#include <math.h>

#include <Windows.h>

#include <fstream>

#include <string>

#include <locale>


using namespace std; // пакет імен стд
int main()
{
    // * змінні
    const double pi = asin(1.0) * 2; // арксинус від одиниці це пі/2, домножую на 2 і виходить пі
    double X = 0, Y = 0, steps = 0;
    int actions = 0, direction = 0, engMenu = 0, ukrMenu = 0, language = 0, appearence = 0, fontSize = 0; // тут виставляю по нулям, бо без цього прога працює неправильно
    string colorChange, background, foreground, input;
    bool error = false;

    do
    {
        // * вибір мови – укр чи англ
        cout << "Choose language: " << endl
             << "1. Ukrainian" << endl
             << "2. English" << endl;
        cout << "Your language: ";
        cin >> input;

        if (isdigit(input[0])) // якщо введене значення (тобто 1 символ чого значення) є числом, то прога буде працювати
        {
            language = stoi(input); // перетворюю рядок інпут на ціле число (стрінг в інт) та присвоюю його змінній, яку буду використовувати в блоці світч

            switch (language)
            {
                // * українське меню
            case 1:
                SetConsoleOutputCP(CP_UTF8); // для норм роботи з укр.мовою на всіх пк змінюється кодування
                do
                {
                    cout << "\nЩо ви хочете зробити? " << endl
                         << "1. Робота з текстовим файлом" << endl
                         << "2. Робота з консоллю" << endl
                         << "3. Перегляд інструкції" << endl
                         << "4. Зміна зовнішнього вигляду консолі" << endl
                         << "5. Вихід з програми \n"
                         << endl;
                    cout << "Вибрано пункт: ";
                    cin >> input;

                    if (isdigit(input[0]))
                    {
                        ukrMenu = stoi(input);

                        switch (ukrMenu)
                        {
                        // * робота з файлом українською
                        case 1:
                        {
                            system("cls"); // очистка консолі

                            X = 0, Y = 0;               // прирівнюю до 0, щоб при тиканні одного і того ж пункту декілька разів кінцева координата не стакалась
                            ifstream cin("mapa.txt");   // відкриваю файл на читання
                            ofstream cout("skarb.txt"); // відкриваю файл на вивід

                            if (!cin.is_open())
                            {
                                cerr << "У вас немає файлу «mapa.txt»!" << endl;
                                break;
                            }
                            // якщо файлу "мапа.тхт" не існує, то видає помилку і закриває прогу

                            cin >> actions;

                            if (actions <= 0 || actions > 40)
                            {
                                cout << "Вказівок не може бути менше 0 чи більше 40, слідуйте інструкціям!" << endl;
                                break;
                            } // якщоо кількість вказівок файлу не відповідає кількості вказівок, дозволених інструкцією – у файл буде написана помилка

                            for (int i = 1; i <= actions; i++)
                            {
                                cin >> direction >> steps;

                                if (direction <= 0 || direction > 8)
                                {
                                    cout << "Число-напрямок може бути від 1 до 8 включаючи. Слідуйте інструкціям!" << endl;
                                    cout.close();
                                    cin.close();
                                    break;
                                } // якщо напрямок не відповідає дозволеним інструкцією – у файл виведеться відповідна помилка

                                if (steps <= 0 || steps > 1000)
                                {
                                    cout << "Число кроків може бути від 1 до 1000. Слідуйте інструкціям!" << endl;
                                    cout.close();
                                    cin.close();
                                    break;
                                } // якщо кількість кроків не відповідає дозволеним інструкцією – у файл виведеться відповідна помилка

                                X = X + sin(pi / 4 * (direction - 1)) * steps; // обрахунок х координати – синус напрямку (кожен напрямок це +45 градусів до 0), помножений на кількість кроків

                                Y = Y + cos(pi / 4 * (direction - 1)) * steps; // обрахунок у координати – косинус напрямку (кожен напрямок це +45 градусів до 0), помножений на кількість кроків
                            }

                            if (abs(X) < 0.001)
                                X = 0; // якщо модуль числа менше 10^-3, то воно фактично дорівнює 0
                            if (abs(Y) < 0.001)
                                Y = 0; // якщо модуль числа менше 10^-3, то воно фактично дорівнює 0

                            cout.precision(3); // кількість знаків після коми, фіксед треба для того, щоб число не окргулялось до менших значень
                            cout << fixed << "Скарб знаходиться за координатами: " << endl
                                 << "X = " << X << " "
                                 << "Y = " << Y << endl;

                            cout.close();
                            cin.close(); // закриваю файли на читання-запис
                            break;
                        }
                        // * робота з консоллю українською
                        case 2:
                        {
                            system("cls"); // очистка консолі

                            X = 0, Y = 0; // прирівнюю до 0, щоб при тиканні одного і того ж пункту декілька разів кінцева координата не стакалась
                            error = false;

                            cout << "\nВведіть кількість дій: ";
                            cin >> actions;

                            if (actions <= 0 || actions > 40)
                            {
                                cout << "\nВказівок не може бути менше 0 чи більше 40, слідуйте інструкціям!\n"
                                     << endl;
                                break;
                            }

                            for (int i = 1; i <= actions; i++)
                            {
                                cout << "Введіть напрямок і кількість кроків: ";
                                cin >> direction >> steps;

                                if (direction <= 0 || direction > 8)
                                {
                                    cout << "\nЧисло-напрямок може бути від 1 до 8 включаючи. Слідуйте інструкціям!\n"
                                         << endl;
                                    error = true;
                                    break;
                                }

                                if (steps <= 0 || steps > 1000)
                                {
                                    cout << "\nЧисло кроків може бути від 1 до 1000. Слідуйте інструкціям!\n"
                                         << endl;
                                    error = true;
                                    break;
                                }

                                X = X + sin(pi / 4 * (direction - 1)) * steps; // обрахунок х координати – синус напрямку (кожен напрямок це +45 градусів до 0), помножений на кількість кроків

                                Y = Y + cos(pi / 4 * (direction - 1)) * steps;
                            }

                            if (!error) // якщо немає помилок про напрямок/кроки
                            {
                                if (abs(X) < 0.001)
                                    X = 0; // якщо модуль числа менше 10^-3, то воно фактично дорівнює 0
                                if (abs(Y) < 0.001)
                                    Y = 0; // якщо модуль числа менше 10^-3, то воно фактично дорівнює 0

                                cout.precision(3); // кількість знаків після коми, фіксед треба для того, щоб число не окргулялось до менших значень
                                cout << fixed << "Скарб знаходиться за координатами: " << endl
                                     << "X = " << X << " "
                                     << "Y = " << Y << endl;
                            }
                            break;
                        }
                        // * ukrInstruction
                        case 3:
                        {
                            system("cls"); // очистка консолі
                            cout << "\nІнструкція:\n"
                                 << endl
                                 << "Знайти закопаний піратами скарб просто: все, що для цього потрібно – це карта. Як відомо, пірати зазвичай малюють карти від руки і описують алгоритм знаходження скаобу так:\n«Встаньте спиною близько самотньої пальми. Пройдіть тридцять кроків у бік лісу, потім сімнадцять кроків у бік озера, ..., нарешті десять кроків в бік великого кругляка. Скарб знаходиться під ним».\nВелика частина таких вказівок просто зводиться до проходження певної кількості кроків в одному з восьми напрямків (1 - північ, 2 - північний схід, 3 - схід, 4 - південний схід, 5 - південь, 6 - південний захід, 7 - захід, 8 - північний захід). Довжина кроку в будь-якому напрямку дорівнює 1." << endl
                                 << "При виборі відповідного пункту меню ви зможете: " << endl
                                 << "1. Працювати з файлами. Програма зчитує дані з файлу mapa.txt. У нього ви маєте завчасно ввести необхідні для правильної роботи програми дані у такому форматі:\nУ перший рядок вводиться кількість вказівок (число від 1 до 40), далі у певну кількість рядків, відповідно кількості вказівок, через Enter вказується напрям руху (цифру від 1 до 8) та кількість кроків у цьому напрямку (від 1 до 1000). Вказівки мають вводитись у форматі «напрям_руху [пробіл] кількість_кроків». Після вибору пункту вас одразу поверне до загального меню. Перевірити результат можна у файлі skarb.txt, де ви побачите відповідь – кінцеву координату скарбу (якщо файлу не було створено завчасно – програма сама його створить).\nЯкщо введена кількість вказівок більша за кількість рядків з вказівками, то вони будуть повторюватись стільки ж разів, скільки і введен число вказівок. Тому для точності бажаного результату рекомендується вводити стільки ж рядків з вказівками, скільки і було введено вказівок.\nЯкщо ж введена кількість вказівок менша за кількість рядків з цими вказівками, то обрахується кількість рядків, відповідна числу вказівок.\nТакож ви можете не закриваючи саму програму змінювати значення у файлі mapa.txt і знову обрахувати кінцеву координату (файл skarb.txt перед цим треба закрити)." << endl
                                 << "2. Робота з консоллю. Працюючи за допомогою консолі, відповідно до тексту-запиту, ви вводите необхідні дані (вказівки – від 1 до 40, напрям руху – цифру від 1 до 8, кількість кроків у цьому напрямку – від 1 до 1000). Формат вводу даних – «напрям_руху [пробіл] кількість_кроків». Кінцева координата теж виводиться у консоль." << endl
                                 << "3. Перегляд інструкції до програми. При виборі цього пункту меню ви маєте можливість прочитати інструкцію, яка пояснить вам як правильно користуватись програмою." << endl
                                 << "4. Зміна зовнішнього вигляду консолі. Ви маєте можливість змінити зовнішній вигляд консолі: колір фону (обираєте потрібний номер чи літеру з списку), колір шрифту (обираєте потрібний номер чи літеру з списку), розмір шрифту (вводите необхідне число).\nВи не можете обрати однаковий колір тексту і фону – у такому випадку програма поверне вас до головного меню.\nЯкщо ви напишите цифру чи літеру крім запропонованих зі списку, то вам видасть повідомлення про помилку англійською. Просто натискаєте Enter і вас знову поверне до пункту 4, де ви зможете переобрати кольори із запропонованих.\nЯкщо ж введена вами літера була з НЕ англійського алфавіту, то помилки не буде, вас просто поверне до п.4." << endl
                                 << "5. Вихід з програми. При виборі даного пункту здійснюється вихід з програми\n"
                                 << endl;
                            break;
                        }
                        case 4:
                        {
                            system("cls"); // очистка консолі

                            do
                            {
                                cout << "\nЩо ви хочете зробити? " << endl;
                                cout << "1. Змінити колір тексту і фону" << endl;
                                cout << "2. Змінити розмір шрифту " << endl;
                                cout << "Ваш вибір: ";
                                cin >> input;

                                if (isdigit(input[0])) // якщо введене значення (тобто 1 символ чого значення) є числом, то прога буде працювати
                                {
                                    appearence = stoi(input); // перетворюю рядок інпут на ціле число (стрінг в інт) та присвоюю його змінній, яку буду використовувати в блоці світч


                                    switch (appearence)
                                    {
                                    case 1:
                                    {
                                        system("cls"); // очистка консолі
                                        cout << "Список кольорів:" << endl
                                             << "0 – Чорний" << endl
                                             << "1 – Синій" << endl
                                             << "2 – Зелений" << endl
                                             << "3 – Аква" << endl
                                             << "4 – Червоний" << endl
                                             << "5 – Бузковий" << endl
                                             << "6 – Жовтий" << endl
                                             << "7 – Білий" << endl
                                             << "8 – Сірий" << endl
                                             << "9 – Світло-синій" << endl
                                             << "А – Світло-зелений" << endl
                                             << "B – Світло-аква" << endl
                                             << "C – Світло-червоний" << endl
                                             << "D – Світло-бузковий" << endl
                                             << "E – Світло-жовтий" << endl
                                             << "F – Яскраво-білий" << endl
                                             << endl;

                                        cout << "Колір тексту: ";
                                        cin >> foreground;
                                        cout << "Колір фону: ";
                                        cin >> background;

                                        colorChange = "color " + background + foreground; // команда для зміни кольору
                                        system(colorChange.c_str());                      // зміна кольору через формування стрінга в сі-подібний массив чарів і повернення вказівника на нього

                                        break;
                                    }
                                    case 2:
                                    {
                                        system("cls"); // очистка консолі
                                        cout << "Введіть бажаний розміру шрифту: ";
                                        cin >> fontSize;

                                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // отримуємо дескріптор консолі
                                        CONSOLE_FONT_INFOEX fontInfo;                      // отримання інфи про шрифт консолі
                                        fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);     // визначення розміру CONSOLE_FONT_INFOEX і прирівнювання fontInfo.cbSize до нього, щоб вінда розуміла очікуваний розмір структури

                                        GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo); // отримання інфи про шрифт консолі на даний момент
                                        fontInfo.dwFontSize.Y = fontSize;                    // установка нового розміру шрифта по висоті

                                        SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo); // юзаєм новий шрифт
                                        break;
                                    }
                                    default:
                                        cout << "\nПросто напишіть 1 чи 2!\n"
                                             << endl;
                                    }
                                }
                                else 
                                {
                                    cout << "\nБудь ласка, напишіть 1 чи 2!\n" // якщо 1 символ введеного значення інпут НЕ є потрібним числом, то виведе прохання написати нормально
                                         << endl;
                                }
                            } while (appearence != 2);
                            break;
                        }
                        // * вихід українською
                        case 5:
                        {
                            cout << "\nЗакриваю програму..." << endl;
                            system("PAUSE");
                            return 0;
                        }
                        default:
                            cout << "\nПросто напишіть 1, 2, 3, 4 чи 5!\n"
                                 << endl;
                        }
                    }
                    else
                    {
                        cout << "\nБудь ласка, напишіть 1, 2, 3, 4 чи 5!\n" // якщо 1 символ введеного значення інпут НЕ є потрібним числом, то виведе прохання написати нормально
                             << endl;
                    }
                } while (ukrMenu != 5);

                system("PAUSE");
                return 0;

            // * engMenu
            case 2:
            {
                do
                {
                    cout << "\nWhat do you want to do? " << endl
                         << "1. Work with files" << endl
                         << "2. Work with the console" << endl
                         << "3. View the instructions for the program" << endl
                         << "4. Changing the appearance of the console" << endl
                         << "5. Exit the program \n"
                         << endl;
                    cout << "Selected item: ";
                    cin >> input;

                    if (isdigit(input[0]))
                    {
                        engMenu = stoi(input); // якщо введене значення (тобто 1 символ чого значення) є числом, то прога буде працювати

                        switch (engMenu) // перетворюю рядок інпут на ціле число (стрінг в інт) та присвоюю його змінній, яку буду використовувати в блоці світч

                        {
                        // * робота з файлом англійською
                        case 1:
                        {
                            system("cls"); // очистка консолі

                            X = 0, Y = 0;               // прирівнюю до 0, щоб при тиканні одного і того ж пункту декілька разів кінцева координата не стакалась
                            ifstream cin("mapa.txt");   // відкриваю файл на читання
                            ofstream cout("skarb.txt"); // відкриваю файл на вивід

                            if (!cin.is_open())
                            {
                                cerr << "You don't have «mapa.txt»!" << endl;
                                break;
                            }
                            // якщо файлу "мапа.тхт" не існує, то видає помилку і закриває прогу

                            cin >> actions;

                            if (actions <= 0 || actions > 40)
                            {
                                cout << "The guidelines cannot be less than 0 or more than 40, follow the instructions!" << endl;
                                break;
                            } // якщоо кількість вказівок файлу не відповідає кількості вказівок, дозволених інструкцією – у файл буде написана помилка

                            for (int i = 1; i <= actions; i++)
                            {
                                cin >> direction >> steps;

                                if (direction <= 0 || direction > 8)
                                {
                                    cout << "The direction number can be from 1 to 8. Follow the instructions!" << endl;
                                    cout.close();
                                    cin.close();
                                    break;
                                } // якщо напрямок не відповідає дозволеним інструкцією – у файл виведеться відповідна помилка

                                if (steps <= 0 || steps > 1000)
                                {
                                    cout << "The number of steps from 1 to 1000. Follow the instructions!" << endl;
                                    cout.close();
                                    cin.close();
                                    break;
                                } // якщо кількість кроків не відповідає дозволеним інструкцією – у файл виведеться відповідна помилка

                                X = X + sin(pi / 4 * (direction - 1)) * steps; // обрахунок х координати – синус напрямку (кожен напрямок це +45 градусів до 0), помножений на кількість кроків

                                Y = Y + cos(pi / 4 * (direction - 1)) * steps; // обрахунок у координати – косинус напрямку (кожен напрямок це +45 градусів до 0), помножений на кількість кроків
                            }

                            if (abs(X) < 0.001)
                                X = 0; // якщо модуль числа менше 10^-3, то воно фактично дорівнює 0
                            if (abs(Y) < 0.001)
                                Y = 0; // якщо модуль числа менше 10^-3, то воно фактично дорівнює 0

                            cout.precision(3); // кількість знаків після коми, фіксед треба для того, щоб число не окргулялось до менших значень
                            cout << fixed << "Coordinates of treasure: " << endl
                                 << "X = " << X << " "
                                 << "Y = " << Y << endl;

                            cin.close();
                            cout.close(); // закриваю файли на читання-запис
                            break;
                        }
                        // * робота з консоллю англійською
                        case 2:
                        {
                            system("cls"); // очистка консолі

                            X = 0, Y = 0; // прирівнюю до 0, щоб при тиканні одного і того ж пункту декілька разів кінцева координата не стакалась
                            error = false;

                            cout << "Enter amount of actions: ";
                            cin >> actions;

                            if (actions <= 0 || actions > 40)
                            {
                                cout << "\nThe guidelines cannot be less than 0 or more than 40, follow the instructions!\n"
                                     << endl;
                                break;
                            }

                            for (int i = 1; i <= actions; i++)
                            {
                                cout << "Enter direction and amount of steps: ";
                                cin >> direction >> steps;

                                if (direction <= 0 || direction > 8)
                                {
                                    cout << "\nThe direction number can be from 1 to 8. Follow the instructions!\n"
                                         << endl;
                                    error = true;
                                    break;
                                }

                                if (steps <= 0 || steps > 1000)
                                {
                                    cout << "\nThe number of steps from 1 to 1000. Follow the instructions!\n"
                                         << endl;
                                    error = true;
                                    break;
                                }

                                X = X + sin(pi / 4 * (direction - 1)) * steps; // обрахунок х координати – синус напрямку (кожен напрямок це +45 градусів до 0), помножений на кількість кроків

                                Y = Y + cos(pi / 4 * (direction - 1)) * steps; // обрахунок у координати – косинус напрямку (кожен напрямок це +45 градусів до 0), помножений на кількість кроків
                            }

                            if (!error) // якщо немає помилок про напрямок/кроки
                            {
                                if (abs(X) < 0.001)
                                    X = 0; // якщо модуль числа менше 10^-3, то воно фактично дорівнює 0
                                if (abs(Y) < 0.001)
                                    Y = 0; // якщо модуль числа менше 10^-3, то воно фактично дорівнює 0

                                cout.precision(3); // кількість знаків після коми, фіксед треба для того, щоб число не окргулялось до менших значень
                                cout << fixed << "Treasure:\n "
                                     << "X = " << X << " , "
                                     << "Y = " << Y << endl;
                            }
                            break;
                        }
                        // * engInstruction
                        case 3:
                        {
                            system("cls"); // очистка консолі
                            cout << "Instruction:\n " << endl
                                 << "Finding treasure buried by pirates is simple: all you need for this is a map. As you know, pirates usually draw maps by hand and describe the algorithm for finding a treasure as follows:\n«Stand with your back near a lonely palm tree. Walk thirty paces towards the forest, then seventeen steps towards the lake, ..., finally ten steps towards the big log. The treasure is under it».\nMost of these instructions simply boil down to taking a certain number of steps in one of eight directions (1 - north, 2 - north-east, 3 - east, 4 - southeast, 5 - south, 6 - southwest, 7 - west, 8 - northwest). The length of a step in any direction is equal to 1." << endl
                                 << "By choosing the appropriate menu item, you can: " << endl
                                 << "1. Work with files. The program reads data from the mapa.txt file. In it, you must enter in advance the data necessary for the correct operation of the program in the following format:\nThe number of instructions is entered in the first line (a number from 1 to 40), then in a certain number of lines, according to the number of instructions, the direction of movement (a number from 1 to 8) and the number of steps in this direction (from 1 to 1000) are indicated through Enter. Directions should be entered in the format «direction_of_movement [space] number_of_steps». After selecting the item, you will be immediately returned to the general menu. You can check the result in the skarb.txt file, where you will see the answer - the final coordinate of the treasure (if the file has not been created in advance, the program will create it itself).\nIf the number of instructions you enter is greater than the number of lines of instructions, the instructions will be repeated as many times as the number of instructions you enter. Therefore, for the accuracy of the desired result, it is recommended to enter the same number of lines with instructions as the number of instructions entered.\nIf the number of instructions entered is less than the number of lines with these instructions, the number of lines corresponding to the number of instructions will be calculated.\nYou can also change the values in the mapa.txt file without closing the program itself and calculate the final coordinate again (the skarb.txt file must be closed before doing so)." << endl
                                 << "2. Work with the console. Working with the console, in accordance with the text-request, you enter the necessary data (directions - from 1 to 40, direction of movement - a number from 1 to 8, number of steps in this direction - from 1 to 1000). The data input format is «direction_of_movement [space] number_of_steps». The final coordinate is also output to the console." << endl
                                 << "3. View the instructions for the program. When choosing this menu item, you have the opportunity to read an instruction that will explain to you how to use the program correctly." << endl
                                 << "4. Change the appearance of the console. You can change the appearance of the console: background color (select the desired number or letter from the list), font color (select the desired number or letter from the list), font size (enter the required number).\nYou can't choose the same text and background color - in this case, the program will return you to the main menu.\nIf you write a number/letter other than the ones in the list, you will receive an error message. Just press Enter and you will be returned to step 4, where you can re-select colors from the list.\nIf the letter you entered was NOT from the English alphabet, there will be no error, you will simply be returned to step 4." << endl
                                 << "5. Exit the program. Selecting this item exits the program\n"
                                 << endl;
                            break;
                        }
                        case 4:
                        {
                            system("cls"); // очистка консолі

                            do
                            {
                                cout << "\nWhat do you want to do?" << endl;
                                cout << "1. Change the color of the text and background" << endl;
                                cout << "2. Change the font size " << endl;
                                cout << "Your choice: ";
                                cin >> input;

                                if (isdigit(input[0])) // якщо введене значення (тобто 1 символ чого значення) є числом, то прога буде працювати
                                {
                                    appearence = stoi(input); // перетворюю рядок інпут на ціле число (стрінг в інт) та присвоюю його змінній, яку буду використовувати в блоці світч


                                    switch (appearence)
                                    {
                                    case 1:
                                    {
                                        system("cls"); // очистка консолі
                                        cout << "List of colors:" << endl
                                             << "0 – Black" << endl
                                             << "1 – Blue" << endl
                                             << "2 – Green" << endl
                                             << "3 – Aqua" << endl
                                             << "4 – Red" << endl
                                             << "5 – Purple" << endl
                                             << "6 – Yellow" << endl
                                             << "7 – White" << endl
                                             << "8 – Gray" << endl
                                             << "9 – Light Blue" << endl
                                             << "А – Light Green" << endl
                                             << "B – Light Aqua" << endl
                                             << "C – Light Red" << endl
                                             << "D – Light Purple" << endl
                                             << "E – Light Yellow" << endl
                                             << "F – Bright White" << endl
                                             << endl;

                                        cout << "The color of the text: ";
                                        cin >> foreground;
                                        cout << "Background color: ";
                                        cin >> background;

                                        colorChange = "color " + background + foreground; // команда для зміни кольору
                                        system(colorChange.c_str());                      // зміна кольору через формування стрінга в сі-подібний массив чарів і повернення вказівника на нього

                                        break;
                                    }
                                    case 2:
                                    {
                                        system("cls"); // очистка консолі
                                        cout << "Enter the desired font size: ";
                                        cin >> fontSize;

                                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // отримуємо дескріптор консолі
                                        CONSOLE_FONT_INFOEX fontInfo;                      // отримання інфи про шрифт консолі
                                        fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);     // визначення розміру CONSOLE_FONT_INFOEX і прирівнювання fontInfo.cbSize до нього, щоб вінда розуміла очікуваний розмір структури

                                        GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo); // отримання інфи про шрифт консолі на даний момент
                                        fontInfo.dwFontSize.Y = fontSize;                    // установка нового розміру шрифта по висоті

                                        SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo); // юзаєм новий шрифт

                                        break;
                                    }
                                    default:
                                        cout << "\nJust print 1 or 2!\n"
                                             << endl;
                                    }
                                }
                                else
                                {
                                    cout << "\nPlease print 1 or 2!\n" << endl; // якщо 1 символ введеного значення інпут НЕ є потрібним числом, то виведе прохання написати нормально
                                }
                            } while (appearence != 2);
                            break;
                        }
                            // * вихід англійською
                        case 5:
                        {
                            cout << "\nClosing the program..." << endl;
                            system("PAUSE");
                            return 0;
                        }
                        default:
                            cout << "\nJust print 1, 2, 3, 4 or 5!\n"
                                 << endl;
                        }
                    }
                    else
                    {
                        cout << "\nPlease print 1, 2, 3, 4 or 5!\n" << endl; // якщо 1 символ введеного значення інпут НЕ є потрібним числом, то виведе прохання написати нормально
                    }
                } while (engMenu != 5);
                break;
            }
            default:
                cout << "\nJust print 1 or 2!\n"
                     << endl;
            }
        }
        else
        {
            cout << "\nPlease print 1 or 2!\n"
                 << endl;
        }
    } while (language != 2);
    system("PAUSE");
    return 0;
}
