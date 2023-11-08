#include <iostream>
#include <vector>

//определяем функцию которая принимает вектор b по ссылке, а также индексы m,n, и p
void swapSegments(std::vector<int>& b, int m, int n, int p) {
    //создаем вектор temp, который хранит элементы сегмента [n,p] из вектора b
    std::vector<int> temp(b.begin() + n, b.begin() + p);
    int j = p - n;
    //сдвигаем элементы [m, m+j) на j позиций вправо. Чтобы освободить место для вставки сегмента temp 
    for (int i = m + j - 1; i >= m; i--) {
        b[i + j] = b[i];  
    }
   // элементы из temp копируются обратно в b, начиная с индекса m и до индекса m + j - 1. Это делается для вставки сегмента temp вместо сегмента[m, m + j)
    for (int i = m; i < m + j; i++) {
        b[i] = temp[i - m];
    }
}

int main() {
    //создается вектор b с исходными значениями
    std::vector<int> b = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //определяются значения индексов m, n и p.
    int m = 1;
    int n = 4;
    int p = 7;
    //Функция swapSegments вызывается с этими значениями
    swapSegments(b, m, n, p);
  //результат выводится на экран с помощью цикла for.
    for (int num : b) {
        std::cout << num << " ";
    }
    std::cout << std::endl;  // 1 5 6 7 2 3 4 8 9

    return 0;
}