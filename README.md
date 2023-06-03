#Karta-Skarbiv_coursework

Українською:

Курсова робота студента 2 курсу 24ї групи ППФК Яценко Віталія на тему "Карта скарбів"

Тема роботи:
Знайти закопаний піратами скарб просто: все, що для цього потрібно - це карта. Як відомо, пірати зазвичай малюють карти від руки і описують алгоритм знаходження скарбу так: "Встаньте близько самотньою пальми. Пройдіть тридцять кроків у бік лісу, потім сімнадцять кроків у бік озера, ..., нарешті десять кроків в бік великого кругляка. Скарб знаходиться під ним". Велика частина таких вказівок просто зводиться до проходження якоїсь кількості кроків в одному з восьми напрямків (1 - північ, 2 - північний схід, 3 - схід, 4 - південний схід, 5 - південь, 6 - південний захід, 7 - захід, 8 - північний захід). Довжина кроку в будь-якому напрямку дорівнює 1. Вам необхідно написати програму, яка за вказівками піратів визначає точку, де заритий скарб.
ФОРМАТ ВХІДНИХ ДАНИХ
Перший рядок вхідного файлу містить число N - число вказівок (1 &lt;= N &lt;= 40). Наступні N рядків містять самі вказівки - номер напрямку (ціле число від 1 до 8) і кількість кроків (ціле число від 1 до 1000). Числа розділені пробілами.
ФОРМАТ ВИХІДНИХ ДАНИХ
У вихідний файл виведіть координати X і Y точки (два дійсних числа, розділені пробілом), де заритий скарб, вважаючи, що вісь Ox спрямована на схід, а вісь Oy - на північ. На початку шукач скарбів повинен стояти на початку координат. Координати необхідно вивести з похибкою не більше 10-3.

Інструкція користувача:
При виборі відповідного пункту меню ви зможете:
1. Працювати з файлами. Програма зчитує дані з файлу mapa.txt. У нього ви маєте завчасно ввести необхідні для правильної роботи програми дані у такому форматі: У перший рядок вводиться кількість вказівок (число від 1 до 40), далі у певну кількість рядків, відповідно кількості вказівок, через Enter вказується напрям руху (цифру від 1 до 8) та кількість кроків у цьому напрямку (від 1 до 1000). Вказівки мають вводитись у форматі «напрям_руху [пробіл] кількість_кроків». Після вибору пункту вас одразу поверне до загального меню. Перевірити результат можна у файлі skarb.txt, де ви побачите відповідь – кінцеву координату скарбу. Також ви можете не закриваючи саму програму змінювати значення у файлі mapa.txt і знову обрахувати кінцеву координату (файл skarb.txt перед цим бажано закрити).
2. Робота з консоллю. Працюючи за допомогою консолі, відповідно до тексту-запиту, ви вводите необхідні дані (вказівки – від 1 до 40, напрям руху – цифру від 1 до 8, кількість кроків у цьому напрямку – від 1 до 1000). Формат вводу даних – «напрям_руху [пробіл] кількість_кроків». Кінцева координата теж виводиться у консоль.
3. Перегляд інструкції до програми. При виборі цього пункту меню ви маєте можливість прочитати інструкцію, яка пояснить вам як правильно користуватись програмою.
4. Зміна зовнішнього вигляду консолі. Ви маєте можливість змінити зовнішній вигляд консолі: колір фону (обираєте потрібний номер з списку), колір шрифту (обираєте потрібний номер з списку), розмір шрифту.
5. Вихід з програми. При виборі даного пункту здійснюється вихід з програми

English:

Course work of the 2nd year student of the 24th group of the PPPC Yatsenko Vitaliy on the topic "Treasure Map"

Theme of the work:
Finding a treasure buried by pirates is easy: all you need is a map. As you know, pirates usually draw maps by hand and describe the algorithm for finding the treasure as follows: "Stand near a lone palm tree. Walk thirty steps towards the forest, then seventeen steps towards the lake, ..., and finally ten steps towards a large cobblestone. The treasure is under it." Most of these instructions simply boil down to walking a certain number of steps in one of eight directions (1 - north, 2 - northeast, 3 - east, 4 - southeast, 5 - south, 6 - southwest, 7 - west, 8 - northwest). The length of a step in any direction is 1. Your task is to write a program that, following the pirates' instructions, determines the point where the treasure is buried.
INPUT FORMAT
The first line of the input file contains the number N - the number of instructions (1 &lt;= N &lt;= 40). The next N lines contain the directions themselves - the number of directions (an integer from 1 to 8) and the number of steps (an integer from 1 to 1000). The numbers are separated by spaces.
OUTPUT FORMAT
In the output file print the X and Y coordinates of the point (two real numbers separated by a space) where the treasure is buried, assuming that the Ox axis is directed to the east and the Oy axis to the north. At the beginning, the treasure hunter must stand at the origin. The coordinates must be printed with an error of no more than 10-3.

User manual:
By choosing the appropriate menu item, you can:
1. Work with files. The program reads data from the mapa.txt file. In it, you must enter in advance the data necessary for the correct operation of the program in the following format:\nThe number of instructions is entered in the first line (a number from 1 to 40), then in a certain number of lines, according to the number of instructions, the direction of movement (a number from 1 to 8) and the number of steps in this direction (from 1 to 1000) are indicated through Enter. Directions should be entered in the format «direction_of_movement [space] number_of_steps». After selecting the item, you will be immediately returned to the general menu. You can check the result in the skarb.txt file, where you will see the answer - the final coordinate of the treasure. You can also change the values in the mapa.txt file and recalculate the final coordinate without closing the program itself (it is advisable to close the skarb.txt file before that).
2. Work with the console. Working with the console, in accordance with the text-request, you enter the necessary data (directions - from 1 to 40, direction of movement - a number from 1 to 8, number of steps in this direction - from 1 to 1000). The data input format is «direction_of_movement [space] number_of_steps». The final coordinate is also output to the console.
3. View the instructions for the program. When choosing this menu item, you have the opportunity to read an instruction that will explain to you how to use the program correctly.
4. Changing the appearance of the console. You can change the appearance of the console: background color (select the desired number from the list), font color (select the desired number from the list), font size.
5. Exit the program. Selecting this item exits the program
