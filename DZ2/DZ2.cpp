// DZ2.cpp 

#include <iostream>

using namespace std;

enum XO { N, X, O };

struct XOField {
    XO field[3][3];
    bool GameOver;
    string playerX;
    string playerO;
};


/*
* Непонятка с этим заданием.
* Получается что для использования структуры
* нужно выставлять значение для всех 3х флагов по отдельности,
* а если выставлять только для одного то другие могут
* оказаться ненулевыми и проверка будет считать что у нас
* int хотя мы пытались записать char, например.
* Как мне кажется удобнее вместо битовых флагов было бы использовать
* enum { isInt , isFloat , isChar } type;
* и тогда достаточно было бы указывать только type и val
* а при проверке делать switch case по type.
* Отсюда вопрос, правильно ли я понял и/или сделал задание?
*/
struct Var {    
    unsigned int isInt : 1;
    unsigned int isFloat : 1;
    unsigned int isChar : 1;
    union {
        int i_val;
        float f_val;
        char c_val;
    } val;
};

void dz1()
{
    short int s = 5;
    int i = 1'345'246;
    long long l = 1'900'067'890'345;
    char ch = 'a';
    bool bl = true;
    float f = 3.14f;
    double d = 12.345667;
}

int main()
{
    XO field[3][3] = { {N,O,X},{O,N,X},{O,X,X} };
    XOField game;
    game.GameOver = false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (field[i][j] == X)
            {
                cout << 'X';
                game.field[i][j] = X;
            }
            else if (field[i][j] == O)
            {
                cout << 'O';
                game.field[i][j] = O;
            }
            else
            {
                cout << ' ';
                game.field[i][j] = N;
            }
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << game.field[i][j];
        }
        cout << endl;
    }

    cout << endl;

    Var arr[5];

    arr[0].isInt = 1;
    arr[0].isFloat = 0;
    arr[0].isChar = 0;
    arr[0].val.i_val = 10;

    arr[1].isInt = 0;
    arr[1].isFloat = 1;
    arr[1].isChar = 0;
    arr[1].val.f_val = 23.12f;

    arr[2].isInt = 0;
    arr[2].isFloat = 0;
    arr[2].isChar = 1;
    arr[2].val.c_val = 'X';

    arr[3].isInt = 0;
    arr[3].isFloat = 1;
    arr[3].isChar = 0;
    arr[3].val.f_val = 34.67f;

    arr[4].isInt = 0;
    arr[4].isFloat = 0;
    arr[4].isChar = 0;
    arr[4].val.i_val = 23;

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i].isInt << ' ' << arr[i].isFloat << ' ' << arr[i].isChar << ' ';
        if (arr[i].isInt) cout << "Int " << arr[i].val.i_val << endl;
        else if (arr[i].isFloat) cout << "Float " << arr[i].val.f_val << endl;
        else if (arr[i].isChar) cout << "Char " << arr[i].val.c_val << endl;
        else cout << "Unknown type";
    };

    return 0;
}

