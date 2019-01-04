/* フィードバックゲインと最適コストを求めるプログラム */
#include <stdio.h>

int main()
{
	/* システム，コスト関数 */
	double A[2][2] = { {0,1},
						{-1,2} };
	double B[2] = { 0,1 };
	double Q[2][2] = { {2,1},
						{1,3} };
	double R = 1;

	/* 初期化 */
	double P[2][2] = { {2,1},
						{1,3} };
	double K[2];

	int N;
	printf("Input N: ");
	scanf("%d", &N);

	printf("K(%d) = (0, 0)\n", N);
	/* 処理 */
	int cnt = 0;
	while (cnt < N) {
		/* 漸化式からKを求める */
		double Work[2];
		Work[0] = P[0][0] * B[0] + P[0][1] * B[1];
		Work[1] = P[0][1] * B[0] + P[1][1] * B[1];
		double G;
		G = B[0] * Work[0] + B[1] * Work[1] + R;

		double Work2[2][2];
		Work2[0][0] = P[0][0] * A[0][0] + P[0][1] * A[1][0];
		Work2[0][1] = P[0][0] * A[0][1] + P[0][1] * A[1][1];
		Work2[1][0] = P[1][0] * A[0][0] + P[1][1] * A[1][0];
		Work2[1][1] = P[1][0] * A[0][1] + P[1][1] * A[1][1];

		K[0] = B[0] * Work2[0][0] + B[1] * Work2[1][0];
		K[1] = B[0] * Work2[0][1] + B[1] * Work2[1][1];
		K[0] /= G;
		K[1] /= G;

		/* 漸化式からPを更新する */
		double Work3[2][2];
		Work3[0][0] = A[0][0]- B[0] * K[0];
		Work3[0][1] = A[0][1] - B[0] * K[1];
		Work3[1][0] = A[1][0] - B[1] * K[0];
		Work3[1][1] = A[1][1] - B[1] * K[1];

		double Work4[2][2];
		Work4[0][0] = P[0][0] * Work3[0][0] + P[0][1] * Work3[1][0];
		Work4[0][1] = P[0][0] * Work3[0][1] + P[0][1] * Work3[1][1];
		Work4[1][0] = P[1][0] * Work3[0][0] + P[1][1] * Work3[1][0];
		Work4[1][1] = P[1][0] * Work3[0][1] + P[1][1] * Work3[1][1];

		P[0][0] = A[0][0] * Work4[0][0] + A[1][0] * Work4[1][0] + Q[0][0];
		P[0][1] = A[0][0] * Work4[0][1] + A[1][0] * Work4[1][1] + Q[0][1];
		P[1][0] = A[0][1] * Work4[0][0] + A[1][1] * Work4[1][0] + Q[1][0];
		P[1][1] = A[0][1] * Work4[0][1] + A[1][1] * Work4[1][1] + Q[1][1];


		printf("K(%d) = (%f, %f)\n", N - cnt - 1, -K[0], -K[1]);
		cnt++;
	}
	printf("(K:Feedback Gain)\n");

	/* 入力 */
	double x[2];
	printf("Input x (in R^2)\n");
	printf("x[0] = ");
	scanf("%lf", &x[0]);
	printf("x[1] = ");
	scanf("%lf", &x[1]);

	double J;
	J = x[0] * (P[0][0] * x[0] + P[0][1] * x[1]) + x[1] * (P[1][0] * x[0] + P[1][1] * x[1]);

	printf("J = %f\n", J);

	return 0;
}
