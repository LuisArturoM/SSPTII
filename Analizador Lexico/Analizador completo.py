#Luis Arturo Maldonado Ramirez

def es_letra(caracter):
    return 'a' <= caracter <= 'z' or 'A' <= caracter <= 'Z'

def es_digito(caracter):
    return '0' <= caracter <= '9'

def analizador_lexico(codigo):
    tokens = []
    longitud_codigo = len(codigo)
    i = 0

    palabras_reservadas = {'if': 19, 'while': 20, 'return': 21, 'else': 22, 'int': 4, 'float': 4, 'void': 4}

    while i < longitud_codigo:
        caracter_actual = codigo[i]

        # identificador: letra(letra|digito)*
        if es_letra(caracter_actual):
            identificador = caracter_actual
            i += 1

            while i < longitud_codigo and (es_letra(codigo[i]) or es_digito(codigo[i])):
                identificador += codigo[i]
                i += 1

            if identificador in palabras_reservadas:
                tipo = palabras_reservadas[identificador]
                tokens.append((tipo, identificador))
            else:
                tokens.append((0, identificador))

        # numero entero: digito+
        elif es_digito(caracter_actual):
            entero_parte = caracter_actual
            i += 1

            while i < longitud_codigo and es_digito(codigo[i]):
                entero_parte += codigo[i]
                i += 1

            # numero Real: int.int
            if i < longitud_codigo and codigo[i] == '.':
                entero_parte += '.'
                i += 1

                real_parte = ''
                while i < longitud_codigo and es_digito(codigo[i]):
                    real_parte += codigo[i]
                    i += 1

                numero_real = float(entero_parte + real_parte)
                tokens.append((2, numero_real))
            else:
                tokens.append((1, int(entero_parte)))

        elif caracter_actual == '"':
            i += 1
            cadena = ''

            while i < longitud_codigo and codigo[i] != '"':
                cadena += codigo[i]
                i += 1

            if i < longitud_codigo and codigo[i] == '"':
                i += 1
                tokens.append((3, cadena))
            else:
                tokens.append((3, cadena))  # si no hay cierre de comillas

        # operadores y simbolos
        elif caracter_actual in ('+', '-'):
            tokens.append((5, caracter_actual))
            i += 1

        elif caracter_actual in ('*', '/'):
            tokens.append((6, caracter_actual))
            i += 1

        elif caracter_actual in ('<', '>', '!', '='):
            op_relacional = caracter_actual

            if i + 1 < longitud_codigo and codigo[i + 1] == '=':
                op_relacional += '='
                i += 1

            if caracter_actual == '=':
                tokens.append((18, op_relacional))
            else:
                tokens.append((7, op_relacional))

            i += 1

        elif caracter_actual == '|':
            if i + 1 < longitud_codigo and codigo[i + 1] == '|':
                tokens.append((8, '||'))
                i += 2
            else:
                tokens.append((13, '|'))
                i += 1

        elif caracter_actual == '&':
            if i + 1 < longitud_codigo and codigo[i + 1] == '&':
                tokens.append((9, '&&'))
                i += 2
            else:
                tokens.append((13, '&'))
                i += 1

        elif caracter_actual == '!':
            tokens.append((10, '!'))
            i += 1

        elif caracter_actual == ';':
            tokens.append((12, ';'))
            i += 1

        elif caracter_actual == ',':
            tokens.append((13, ','))
            i += 1

        elif caracter_actual == '(':
            tokens.append((14, '('))
            i += 1

        elif caracter_actual == ')':
            tokens.append((15, ')'))
            i += 1

        elif caracter_actual == '{':
            tokens.append((16, '{'))
            i += 1

        elif caracter_actual == '}':
            tokens.append((17, '}'))
            i += 1

        # ignorar espacios en blanco y saltos de linea
        elif caracter_actual in (' ', '\t', '\n', '\r'):
            i += 1

        else:
            i += 1  # ignorar caracteres no reconocidos

    tokens.append((23, '$'))  # agregar simbolo de fin de cadena
    return tokens

cadena_prueba = 'int a = 10 float b = 0.2 if (x <= 10) { return x + 5; } else { return x - 5; }'
resultado = analizador_lexico(cadena_prueba)

print("Tokens:")
for tipo, valor in resultado:
    print(f"{tipo}: {valor}")