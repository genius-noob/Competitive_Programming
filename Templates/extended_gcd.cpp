int ainv, binv;
void extgcd(int a, int b){
    if(b == 0) {
        hcf = a;
        ainv = 1;
        binv = 0;
    } 
    else{
        extgcd(b, a%b);
        int temp = ainv;
        ainv = binv;
        binv = temp - (a/b)*binv; 
    } 
}
