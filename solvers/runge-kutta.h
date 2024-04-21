// TODO: Fix k_i
float** runge_kutta(unsigned M, 
        unsigned N, 
        float* t, 
        void (*dxdt)(float*, float, unsigned, float*),
        float* X0) 
{
    float** result = (float**) malloc(sizeof(float*) * N);
    for (int i=0; i<N; i++) {
        result[i] = (float*) malloc(sizeof(float)*M);
    }

    for (int i=0; i<M; i++) {
        result[0][i] = X0[i];
    }

    float* k1 = (float*) malloc(sizeof(float) * M);
    float* k2 = (float*) malloc(sizeof(float) * M);
    float* k3 = (float*) malloc(sizeof(float) * M);
    float* k4 = (float*) malloc(sizeof(float) * M);

    float* tmp = (float*) malloc(sizeof(float) * M);

    for (int i=1; i<N; i++) {

        float h = t[i] - t[i-1];

        // compute k_i
        // k_1
        for (int j=0; j<M; j++) {
            tmp[j] = result[i-1][j];
        }
        dxdt(tmp, t[i-1], M, k1);

        // k_2
        for (int j=0; j<M; j++) {
            tmp[j] = result[i-1][j] + h/2.0f*k1[j];
        }
        dxdt(tmp, t[i-1] + h/2.0, M, k2);

        // k_3
        for (int j=0; j<M; j++) {
            tmp[j] = result[i-1][j] + h/2.0f*k2[j];
        }
        dxdt(tmp, t[i-1] + h/2.0, M, k3);

        // k_4
        for (int j=0; j<M; j++) {
            tmp[j] = result[i-1][j] + h*k3[j];
        }
        dxdt(tmp, t[i-1] + h, M, k4);


        // compute result[i][j]
        for (int j=0; j<M; j++) {
            result[i][j] = result[i-1][j] + 
                h/6.0f * (k1[j] + 2.0f*k2[j] + 2.0f*k3[j] + k4[j]);
        }

    }

    free(k1);
    free(k2);
    free(k3);
    free(k4);

    free(tmp);
    //free(tmpd);

    return result;
}
