/**************************************************/
/*        Programacion para mecatronicos          */
/* Nombre:     Enders Jose Fuma Santana           */
/* Matricula:  2026-0304                          */
/* Seccion:    Sabados                            */
/* Practica:   Primer Parcial C3 2026 Sabado      */
/* Fecha:      06/10/2026                         */
/**************************************************/
/*
 * Reto 20 - Filtrado: reduccion entre etapas consecutivas
 *
 * Regla: desde la segunda fila, un valor x es evento si la reduccion
 * respecto a la fila anterior (v - x) esta entre L y U (inclusive).
 * Impacto del evento: v - x + 1.
 */
#include <stdio.h>

int main(void)
{
    int N, M, L, U;
    int mat[30][30];          /* matriz de datos (no se modifica)        */
    int eventos[30];          /* cantidad de eventos por fila            */
    long impacto[30];         /* suma de impactos por fila               */
    int racha[30];            /* longitud de la mayor racha por fila     */
    int inicio[30];           /* columna (base 1) donde empieza la racha */
    int colEv[30];            /* eventos por columna                     */
    int i, j, v, x;
    int actual, inicioActual;
    int mejor, colMejor;

    /* ---------- Lectura y validacion de encabezado ---------- */
    if (scanf("%d %d %d %d", &N, &M, &L, &U) != 4) {
        printf("ERROR\n");
        return 0;
    }
    if (N < 1 || N > 30 || M < 1 || M > 30 ||
        L < 0 || L > 1000 || U < 0 || U > 1000 || L > U) {
        printf("ERROR\n");
        return 0;
    }

    /* ---------- Lectura y validacion de la matriz ---------- */
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (scanf("%d", &mat[i][j]) != 1 ||
                mat[i][j] < 0 || mat[i][j] > 1000) {
                printf("ERROR\n");
                return 0;
            }
        }
    }

    /* ---------- Inicializacion de acumuladores ---------- */
    for (j = 0; j < M; j++)
        colEv[j] = 0;

    /* ---------- Eventos, impactos y rachas por fila ---------- */
    for (i = 0; i < N; i++) {
        eventos[i] = 0;
        impacto[i] = 0;
        racha[i] = 0;
        inicio[i] = 0;
        actual = 0;
        inicioActual = 0;

        for (j = 0; j < M; j++) {
            x = mat[i][j];
            /* i >= 1 evita acceder a la fila -1 (la fila 1 no genera eventos) */
            if (i >= 1) {
                v = mat[i - 1][j];
                if (v - x >= L && v - x <= U) {
                    /* Hay evento */
                    eventos[i]++;
                    impacto[i] += v - x + 1;
                    colEv[j]++;
                    if (actual == 0)
                        inicioActual = j + 1;   /* nueva racha */
                    actual++;
                    /* '>' estricto: ante empate se conserva la racha que empieza antes */
                    if (actual > racha[i]) {
                        racha[i] = actual;
                        inicio[i] = inicioActual;
                    }
                } else {
                    actual = 0;                 /* sin evento: se corta la racha */
                }
            } else {
                actual = 0;
            }
        }
    }

    /* ---------- Fila prioritaria ---------- */
    mejor = 0;   /* 0 = ningun evento en toda la matriz */
    for (i = 0; i < N; i++) {
        if (eventos[i] == 0)
            continue;
        if (mejor == 0) {
            mejor = i + 1;
        } else {
            int b = mejor - 1;
            if (racha[i] > racha[b] ||
                (racha[i] == racha[b] && impacto[i] > impacto[b]) ||
                (racha[i] == racha[b] && impacto[i] == impacto[b] &&
                 eventos[i] > eventos[b]))
                mejor = i + 1;   /* en empate total se queda la fila menor */
        }
    }

    /* ---------- Columna destacada ---------- */
    colMejor = 0;
    for (j = 0; j < M; j++) {
        if (colEv[j] > 0 && (colMejor == 0 || colEv[j] > colEv[colMejor - 1]))
            colMejor = j + 1;
    }

    /* ---------- Salida ---------- */
    for (i = 0; i < N; i++)
        printf("FILA %d EVENTOS %d IMPACTO %ld RACHA %d INICIO %d\n",
               i + 1, eventos[i], impacto[i], racha[i], inicio[i]);
    printf("COLUMNAS");
    for (j = 0; j < M; j++)
        printf(" %d", colEv[j]);
    printf("\n");
    printf("PRIORIDAD %d\n", mejor);
    printf("COLUMNA %d\n", colMejor);

    return 0;
}
