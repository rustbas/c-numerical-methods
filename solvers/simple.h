float** solve(unsigned M, 
        unsigned N, 
        float* t, 
        float* (*dxdt)(float*, float, unsigned),
        float* X0) 
{
    float** result = (float**) malloc(sizeof(float*) * N);
    for (int i=0; i<N; i++) {
        result[i] = (float*) malloc(sizeof(float)*M);
    }

    float* tmp = (float*) malloc(sizeof(float) * M);
    for (int i=0; i<M; i++) {
        tmp[i] = X0[i];
        result[0][i] = tmp[i];
    }

    float* tmpd = (float*) malloc(sizeof(float) * M);

    for (int i=1; i<N; i++) {

        tmpd = dxdt(result[i-1], t[i], M);

        for (int j=0; j<M; j++) {
            result[i][j] = result[i-1][j] + tmpd[j] * (t[i] - t[i-1]);
        }


    }

    free(tmp);
    free(tmpd);

    return result;
}
