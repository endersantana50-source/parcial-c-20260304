# Parcial de algoritmos en C

- **Nombre:** Enders José Fuma Santana
- **Matrícula:** 20260304
- **Asignatura:** Programación para mecatrónicos
- **Sección:** Sábados
- **Práctica:** Primer Parcial C3 2026 Sábado
- **Reto:** 20 - Filtrado: reducción entre etapas consecutivas

## Compilar y ejecutar

```
mkdir -p build
gcc -std=c11 -Wall -Wextra 20260304.c -o build/reto
./build/reto < Pruebas/caso_01.in
```

Para comparar con la salida esperada:

```
./build/reto < Pruebas/caso_01.in | diff --strip-trailing-cr - Pruebas/caso_01.out
```

Si no se imprime nada, la salida coincide.

## Contenido

- `20260304.c`: programa final.
- `etapa1_20260304.c`, `etapa2_20260304.c`, `etapa3_20260304.c`: avances del código fuente.
- `Informe_20260304.pdf`: informe con análisis, pseudocódigo y prueba de escritorio.
- `Pruebas/`: los 17 casos proporcionados (`.in` / `.out`).
- `Evidencias/`: dos pruebas propias (A y B) con entrada y salida esperada.

## Estado

Programa terminado; pasa los 17 casos de prueba y las 2 pruebas propias.
