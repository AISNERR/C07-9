/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michaelaisner <michaelaisner@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:18:34 by sgaladri          #+#    #+#             */
/*   Updated: 2025/03/08 17:49:59 by michaelaisn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_stock_str
{
    int size;
    char *str;
    char *copy;
} t_stock_str;

// Функция для получения длины строки
int ft_strlen(int i)
{
    int length = 0;
    while (length < i)
        length++;
    return (length);
}

// Функция освобождения памяти
void ft_free(int i, t_stock_str *massive)
{
    while (i >= 0)
    {
        free(massive[i].copy);
        i--;
    }
    free(massive);
}

// Функция копирования строки
char *ft_strcpy(char *str, int size)
{
    char *ret;
    int i = 0;

    ret = malloc(sizeof(char) * (size + 1));
    if (!ret)
        return NULL;
    while (str[i])
    {
        ret[i] = str[i];
        i += 1;
    }
    ret[i] = '\0';
    return ret;
}

// Функция, создающая массив структур
t_stock_str *ft_strs_to_tab(int ac, char **av)
{
    t_stock_str *buff;
    int i = 0;

    buff = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
    if (!buff)
        return NULL;

    while (i < ac)
    {
        buff[i].size = ft_strlen(strlen(av[i]));
        buff[i].copy = ft_strcpy(av[i], buff[i].size);
        if (buff[i].copy == NULL)
        {
            ft_free(i - 1, buff);
            return NULL;
        }
        buff[i].str = av[i];
        i++;
    }
    buff[i].size = 0;
    buff[i].copy = 0;
    buff[i].str = 0;
    return buff;
}

// Функция для вывода массива структур
void ft_print_structs(t_stock_str *arr)
{
    int i = 0;
    while (arr[i].str)
    {
        printf("Original: %s\n", arr[i].str);
        printf("Copy    : %s\n", arr[i].copy);
        printf("Size    : %d\n\n", arr[i].size);
        i++;
    }
}

// Главная функция для тестирования
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Использование: %s <строка1> <строка2> ...\n", argv[0]);
        return 1;
    }

    // Создаём массив структур
    t_stock_str *array = ft_strs_to_tab(argc - 1, argv + 1);

    if (!array)
    {
        printf("Ошибка при создании массива структур.\n");
        return 1;
    }

    // Выводим результат
    ft_print_structs(array);

    // Освобождаем память
    ft_free(argc - 2, array);

    return 0;
}

