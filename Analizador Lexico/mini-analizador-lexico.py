#Luis Arturo Maldonado Ramirez

def es_letra(caracter):
    return 'a' <= caracter <= 'z' or 'A' <= caracter <= 'Z'

def es_digito(caracter):
    return '0' <= caracter <= '9'

def analizador_lexico(codigo):
    tokens = []
    longitud_codigo = len(codigo)
    i = 0

    while i < longitud_codigo:
        caracter_actual = codigo[i]

        # Identificador: letra(letra|digito)*
        if es_letra(caracter_actual):
            identificador = caracter_actual
            i += 1

            while i < longitud_codigo and (es_letra(codigo[i]) or es_digito(codigo[i])):
                identificador += codigo[i]
                i += 1

            tokens.append(('IDENTIFICADOR', identificador))

        # Número Real: entero.entero+
        elif es_digito(caracter_actual):
            entero_parte1 = caracter_actual
            i += 1

            while i < longitud_codigo and es_digito(codigo[i]):
                entero_parte1 += codigo[i]
                i += 1

            if i < longitud_codigo and codigo[i] == '.':
                entero_parte2 = ''
                i += 1

                while i < longitud_codigo and es_digito(codigo[i]):
                    entero_parte2 += codigo[i]
                    i += 1

                numero_real = f"{entero_parte1}.{entero_parte2}"
                tokens.append(('REAL', numero_real))
            else:
                tokens.append(('ENTERO', entero_parte1))

        else:
            i += 1  # Ignorar caracteres no reconocidos

    return tokens

# Ejemplo de uso
codigo = input("Introduce tu identificador / numero real\n")
resultado = analizador_lexico(codigo)

print("Tokens:")
for tipo, valor in resultado:
    print(f"{tipo}: {valor}")