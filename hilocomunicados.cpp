#include <iostream>
#include <string>
#include <iomanip>  

using namespace std;

string s1, s2;
int resObj;

double f(int i, int res) {
    
    if (i == s2.size()) {

        // cb 1 ->si llegamos a la misma respuesta que con s1
        if (res == resObj) return 1;

        // cb 2 si no es la misma
        else { 
            return 0;
        }
    }

    //casos recursivos
    if (s2[i] == '+') {

        return f(i + 1, res + 1);

    } else if (s2[i] == '-') {

        return f(i + 1, res - 1);

    } else { // si s2[i] == '?'

        //tenemos 50% de chances con las dos opciones, si por uno no resulta la recursion va a devolver 0

        return 0.5 * f(i + 1, res + 1) + 0.5 * f(i + 1, res - 1);
    }
}

int main() {

    cin >> s1 >> s2;


    for (char c : s1) {
        
        if (c == '+') resObj++;
        else if (c == '-') resObj--;
    }

    cout << fixed << setprecision(12) << f(0, 0) << endl;

    return 0;
}
