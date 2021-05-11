﻿#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    cout << "Введите количество элементов в бинарном дереве:" << endl;
    do {
        cout << ">";
        cin >> array_numbers_size;
        if (array_numbers_size < 1)
            cout << "Введите положительное число" << endl;
    } while (array_numbers_size < 1);
    array_numbers = new double[array_numbers_size];
    BinaryTree tree;
    cout << "Введите вещественные числа:\n";
    tree.create_balanced_binary_tree(array_numbers_size);
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t\t\tВЫВОД БИНАРНОГО ДЕРЕВА";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\tГлубина дерева: " << tree.depth_tree();
    tree.print_tree();
    cout << "\n\n\n\n";
    system("pause");
    system("cls");
    BinaryTree search_tree;
    for (int i = 0; i < array_numbers_size; i++)
        search_tree.insert_in_search_tree(array_numbers[i]);
    isBalancedSortPrinting = false;
    cout << "\t\t\t\t\t\t\t\t\t\t\tВЫВОД БИНАРНОГО ДЕРЕВА ПОИСКА";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\tГлубина дерева: " << search_tree.depth_tree();
    search_tree.print_tree();
    cout << "\n\n\n\n";
    system("pause");
    cout << endl;
    search_tree.amount_of_leaves();
    cout << "Количество листьев в дереве: " << i << endl;
    system("pause");
    return 0;
}