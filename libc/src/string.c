#include "stdint.h"
#include "stddef.h"
#include "memory.h"
#include "string.h"

/**
 * @brief - Проверяет является ли символ буквенно-циф­ровым значением
 *
 * @param char c - Символ
 *
 * @return - Возвращает ненулевое значение, если его аргумент является либо буквой ал­фавита (верхнего или нижнего регистра), либо цифрой.
 */
bool isalnum(char c){
    return  (c >= '0' && c <= '9') ||
            (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ;
}

bool isspace(char c) {
	return c == ' ' || c == '\n' || c == '\t';
}

/**
 * @brief Проверяет, является ли символ формата UTF-8
 *
 * @param с - Символ
 *
 * @return bool - true если да
 */
bool isUTF(char c) {
    if (c == -47 || c == -48){
        return true;
    }
    return false;
}

/**
 * @brief Проверяет, является ли специальным символом
 *
 * @param с - Символ
 *
 * @return bool - true если да
 */
bool isSymbol(char c){
    if (c == -62 || c == -106 || c == -30){
        return true;
    }
    return false;
}

/**
 * @brief Возращает индекс символа
 *
 * @param с - Символ
 * @param с1 - Символ
 *
 * @warning зачем нам c и c1 если нужен short c?
 * @return индекс символа
 */
uint32_t UTFConvert(char c, char c1){
    return (isUTF(c)?((((int) c)* -1)+(((int) c1)* -1)):((int) c));
}

/**
 * @brief Возращает длину строки с учетом UTF-8
 *
 * @param str - Строка
 *
 * @return size_t - Длину символов
 */
size_t mb_strlen(const char *str){
    size_t len = 0;
    const size_t def = strlen(str);

    for(size_t i = 0; i < def;i++){
        if (isUTF(str[i])) continue;
        len++;
    }
    return len;
}

/**
 * @brief Возвращает индекс символа в строке
 *
 * @param str - строка
 * @param find - символ, индекс которого надо найти в строке
 */
size_t struntil(const char* str, const char find) {
    size_t len = 0;

    while(str[len] && str[len] != find)
        len++;

    return len;
}

/**
 * @brief Объединение строк
 *
 * @param s - Указатель на массив в который будет добавлена строка
 * @param t - Указатель на массив из которого будет скопирована строка
 *
 * @return char* - Функция возвращает указатель на массив, в который добавлена строка
 */
char* strcat(char* destination, const char* source) {
    char* ptr = destination;

    // Находим конец строки в destination
    while (*ptr != '\0') {
        ptr++;
    }

    // Копируем символы из source в конец destination
    while (*source != '\0') {
        *ptr = *source;
        ptr++;
        source++;
    }

    // Добавляем завершающий нулевой символ в destination
    *ptr = '\0';

    return destination;
}

/**
 * @brief Проверяет, является ли строка числом
 *
 * @param c - Указатель на строку.
 *
 * @return bool - если строка является числом
 */
bool isNumber(const char* c) {
    for(uint32_t i = 0, len = strlen(c); i < len; i++){
        if (!(c[i] >= '0' && c[i] <= '9')) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Конвертируем число в символы
 *
 * @param n - Число
 * @param buffer - символы
 * @return Длина строки
 */
size_t itou(size_t n, char *buffer) {
    char* p = buffer;

    size_t s = n;

    do {
        ++p;
        s = s / 10;
    } while(s);

    *p = '\0';

    do {
        *--p = '0' + (n % 10);
        n = n / 10;
    } while(n);

    return strlen(buffer);
}

/**
 * @brief Конвертируем число HEX в символы
 *
 * @param n - Число
 * @param buffer - символы
 * @return Длина строки
 */
size_t itoh(size_t i, char *buffer) {
    const unsigned char hex[16] __attribute__((nonstring)) = "0123456789ABCDEF";
    uint32_t n, d = 0x10000000;
    char* p = buffer;

    while ((i / d == 0) && (d >= 0x10)) {
        d /= 0x10;
    }
    n = i;

    while (d >= 0xF) {
        *p++ = hex[n / d];
        n = n % d;
        d /= 0x10;
    }

    *p++ = hex[n];
    *p = 0;

    return strlen(buffer);
}

/**
 * @brief - ???
 *
 * @param  const char *s1 - ???
 * @param const char *s2  - ???
 *
 * @return - ???
 */
int dcmpstr( const char *s1, const char *s2 )
{
    while ( *s1 && *s1 == *s2 ) ++s1, ++s2;

    return ( ( unsigned char )*s1 > ( unsigned char )*s2 ) -
           ( ( unsigned char )*s1 < ( unsigned char )*s2 );
}

/**
 * @brief - ???
 *
 * @param size_t num - ???
 *
 * @return - ???
 */
char digit_count(size_t num) {
    if(num == 0)
        return 1;

    char count = 0;
    while(num > 0) {
        num /= 10;
        count++;
    }
    return count;
}

/**
 * @brief - ???
 *
 * @param size_t num - ???
 *
 * @return - ???
 */
char hex_count(size_t num) {
    if(num == 0)
        return 1;

    char _ = 0;
    while(num > 0) {
        num /= 16;
        _++;
    }
    return _;
}
/**
 * @brief - Проверяет строку на числовое значение
 *
 * @param char* a - Буфер
 *
 * @return - true, если вся строка число
 */

bool isnumberstr(char* a) {
    while(*a) {
        if(!isdigit(*a)) {
            return false;
        }
        a++;
    }

    return true;
}

/**
 * @brief Посчитать количество символов `character` в строке `string`
 *
 * @param s1 - Строка
 * @param character - Символ
 *
 * @return size_t - количество найденных символов в строке
 */
size_t strcount(const char* string, char character) {
    size_t count = 0;

    while(*string++) {
        if(*string == character)
            count++;
    }

    return count;
}

/**
 * @brief - Преобразование строки в значение типа unsigned long int. Анализируя строку string, strtoul интерпретирует её содержимое в без знаковое  целое число типа unsigned long int.
 *
 * @param const char* str - Си-строка для выполнения преобразования.
 * @param char** endptr - Ссылка на объект типа char*, значение которой содержит адрес следующего символа в строке string, сразу после предыдущего найденного числа. Если этот параметр не используется, он должен быть нулевым указателем.
 * @param int base - Основание системы исчисления.
 *
 * @return - В случае успеха, функция возвращает целое число преобразованное к типу данных unsigned long int.
 * Если в строке не было найдено целое число, функция возвращает нулевое значение.
 */
unsigned long strtoul(const char* str, char** endptr, int base) {
    unsigned long result = 0;
    int i = 0;

    // Пропускаем начальные пробелы
    while (str[i] == ' ') {
        i++;
    }

    // Преобразуем основание base в случае необходимости
    if (base == 0) {
        if (str[i] == '0') {
            if (str[i + 1] == 'x' || str[i + 1] == 'X') {
                base = 16;
                i += 2;
            } else {
                base = 8;
                i++;
            }
        } else {
            base = 10;
        }
    }

    // Обрабатываем число
    while (str[i] != '\0') {
        int digit;
        if (str[i] >= '0' && str[i] <= '9') {
            digit = str[i] - '0';
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            digit = str[i] - 'a' + 10;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            digit = str[i] - 'A' + 10;
        } else {
            break;
        }
        if (digit < base) {
            result = result * base + digit;
            i++;
        } else {
            break;
        }
    }

    // Устанавливаем значение endptr
    if (endptr != NULL) {
        *endptr = (char*)(str + i);
    }

    return result;
}

char* strdynamize(const char* str) {
    size_t len = strlen(str);

    char* mem = malloc(len + 1);
    strcpy(mem, str);

    return mem;
}
