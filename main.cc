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



DrapeResult drape(double* body_vertices, double* cloth_vertices, double* pose, double* trans) {
    int batch_size = 1;
    

}

// 이건 필요없다. 이미 A pose에서 구한것을 가져오면 되니까 미리 계산해두고 Unreal에 넘겨주는 방식을 택했다.
double* get_lbs_weights(double* body_vertices, double* cloth_vertices, double* body_lbs_weights, int K=10) {

}

double* set_pose(double[] can_vertes, pose, trans, lbs_weight) {
        /*
        *** INPUT ***
            can_verts: [batch_size, N_V, 3]
            pose: [batch_size, 63]
        */

    int N_V = 
    int N_K = 55
    reshape비슷한것을 해야함
    global_orient
    pose;
    double* riggedJaw = jaw_pose.reshape;
    double* riggedLeftEye = leye_pose.reshape;
    double* riggedRightEye = reye_pose.reshape
    double* riggedLeftHand = einsum(leftHand_pose, left_hand_Component);
    double* riggedRightHand = einsum(rightHand_pose, right_hand_component);


    can_pose
}

// n*m matrix가 들어왔을때 col별로 더한 matrix return
double* einsum(double* matrixA, double* matrixB, int p, int q, int r) {
    // matrixC는 matrixA와 matrixB의 multiplication을, 
    // matrixA: [p][q]
    // matrixB: [q][r]
    // matrixC: [p][r]
    // matrixD: [r]

    // matrixD는 matrixC의 column-wise summation을 담는다.

    double* matrixC = matmul(matrixA, matrixB, p, q, r);
    double* matrixD;

    for (int col=0; col<m; col++) {
        int sum = 0;
        for (int row=0; row<n; row++) {
            sum += matrixC[row*m + col];
        }
        matrixD[col] = sum;
    }
    return matrixC
}

double* matmul(double* matrixA, double* matrixB, int p, int q, int r) {
    double* matrixC;
    for (int i = 0; i < p; i++)
      for (int j = 0; j < r; j++)
        for (int k = 0; k < q; k++)
            matrixC[i * p + j] += matrixA[i * p + k] * matrixB[k * q + j];
}