#include <iostream>

using namespace std;


struct DrapeResult {
    double T_vertices[1];
    double T_cloth_vertices[1];
    double vertices[1];
    double cloth_vertices[1]
};

int main() {


}



DrapeResult drape(double[] body_vertices, double[] cloth_vertices, double[] pose,double[] trans) {
    int batch_size = 1;
    

}

// 이건 필요없다. 이미 A pose에서 구한것을 가져오면 되니까 미리 계산해두고 Unreal에 넘겨주는 방식을 택했다.
double[] get_lbs_weights(double[] body_vertices, double[] cloth_vertices, double[] body_lbs_weights, int K=10) {
}