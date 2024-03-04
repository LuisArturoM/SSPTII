#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// Definición de tokens
enum class TipoToken {
    IDENTIFICADOR,
    LITERAL_NUMERICO,
    PALABRA_CLAVE,
    OPERADOR,
    DELIMITADOR,
    COMENTARIO,
    INVALIDO
};

struct Token {
    TipoToken tipo;
    string lexema;
};

// Función para verificar si un string es una palabra clave
bool esPalabraClave(const string& palabra) {
    vector<string> palabrasClave = { "si", "sino", "mientras", "para", "entero", "flotante", "retorno" };
    for (const auto& palabraClave : palabrasClave) {
        if (palabra == palabraClave) {
            return true;
        }
    }
    return false;
}

// Función para procesar el código fuente y producir tokens
vector<Token> tokenizar(const string& codigoFuente) {
    vector<Token> tokens;
    string tokenActual;
    TipoToken tipoActual = TipoToken::INVALIDO;

    for (char c : codigoFuente) {
        if (isspace(c)) {
            if (!tokenActual.empty()) {
                Token token;
                token.lexema = tokenActual;
                if (tipoActual == TipoToken::INVALIDO) {
                    if (isalpha(tokenActual[0])) {
                        token.tipo = esPalabraClave(tokenActual) ? TipoToken::PALABRA_CLAVE : TipoToken::IDENTIFICADOR;
                    }
                    else if (isdigit(tokenActual[0])) {
                        token.tipo = TipoToken::LITERAL_NUMERICO;
                    }
                    else {
                        token.tipo = TipoToken::INVALIDO;
                    }
                }
                else {
                    token.tipo = tipoActual;
                }
                tokens.push_back(token);
                tokenActual.clear();
                tipoActual = TipoToken::INVALIDO;
            }
        }
        else if (ispunct(c)) {
            if (!tokenActual.empty()) {
                Token token;
                token.lexema = tokenActual;
                token.tipo = esPalabraClave(tokenActual) ? TipoToken::PALABRA_CLAVE : TipoToken::IDENTIFICADOR;
                tokens.push_back(token);
                tokenActual.clear();
            }
            Token token;
            token.lexema = c;
            token.tipo = TipoToken::DELIMITADOR;
            tokens.push_back(token);
        }
        else {
            tokenActual += c;
        }
    }

    // Procesar el último token
    if (!tokenActual.empty()) {
        Token token;
        token.lexema = tokenActual;
        if (tipoActual == TipoToken::INVALIDO) {
            if (isalpha(tokenActual[0])) {
                token.tipo = esPalabraClave(tokenActual) ? TipoToken::PALABRA_CLAVE : TipoToken::IDENTIFICADOR;
            }
            else if (isdigit(tokenActual[0])) {
                token.tipo = TipoToken::LITERAL_NUMERICO;
            }
            else {
                token.tipo = TipoToken::INVALIDO;
            }
        }
        else {
            token.tipo = tipoActual;
        }
        tokens.push_back(token);
    }

    return tokens;
}

// Función para imprimir tokens
void imprimirTokens(const vector<Token>& tokens) {
    for (const auto& token : tokens) {
        cout << "Tipo: ";
        switch (token.tipo) {
        case TipoToken::IDENTIFICADOR:
            cout << "Identificador";
            break;
        case TipoToken::LITERAL_NUMERICO:
            cout << "Literal Numérico";
            break;
        case TipoToken::PALABRA_CLAVE:
            cout << "Palabra Clave";
            break;
        case TipoToken::OPERADOR:
            cout << "Operador";
            break;
        case TipoToken::DELIMITADOR:
            cout << "Delimitador";
            break;
        case TipoToken::COMENTARIO:
            cout << "Comentario";
            break;
        case TipoToken::INVALIDO:
            cout << "Inválido";
            break;
        }
        cout << ", Lexema: " << token.lexema << endl;
    }
}

int main() {
    ifstream archivoEntrada("input.txt");
    if (!archivoEntrada.is_open()) {
        cerr << "Error al abrir el archivo de entrada." << endl;
        return 1;
    }

    string codigoFuente((istreambuf_iterator<char>(archivoEntrada)), (istreambuf_iterator<char>()));

    vector<Token> tokens = tokenizar(codigoFuente);
    imprimirTokens(tokens);

    return 0;
}