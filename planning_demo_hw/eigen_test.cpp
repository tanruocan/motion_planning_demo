//#include <iostream>
//#include <Eigen/Dense>
//#include <Eigen/Core>
//
//using namespace std;
//
//int main()
//{
////	Eigen::Matrix<double, 6, 6> e_mat;
////	int n = 6;
////	int m = 6;
////	double t0 = 0.0;
////	double t1 = 3.0;
////	
////	for (int j = 0; j < n; ++j)
////	{
////		e_mat(0,j) = pow(t0, n - j -1);
////		e_mat(1, j) = (n - j) * pow(t0, n - j - 2);
////		e_mat(2, j) = (n - j) * (n - j - 1) * pow(t0, n - j - 3);
////
////		if (n - j - 2 < 0)
////		{
////			e_mat(1, j) = 0.0;
////		}
////
////		if (n - j - 3 < 0)
////		{
////			e_mat(2, j) = 0.0;
////		}
////	}
////
////	for (int j = 0; j < n; ++j)
////	{
////		e_mat(3, j) = pow(t1, n - j - 1);
////		e_mat(4, j) = (n - j - 1) * pow(t1, n - j - 2);
////		e_mat(5, j) = (n - j - 1) * (n - j - 2) * pow(t1, n - j - 3);
////
////		if (n - j - 2 < 0)
////		{
////			e_mat(4, j) = 0.0;
////		}
////
////		if (n - j - 3 < 0)
////		{
////			e_mat(5, j) = 0.0;
////		}
////	}
////
//	Eigen::Matrix<double, 6, 1> e_vector;
//	e_vector(0, 0) = 1;
//	e_vector(1, 0) = 2;
//	e_vector(2, 0) = 3;
//	e_vector(3, 0) = 4;
//	e_vector(4, 0) = 5;
//	e_vector(5, 0) = 6;
//	
//	cout << e_vector << endl;
//
//	system("pause");
//	return 0;
//
//
//}
