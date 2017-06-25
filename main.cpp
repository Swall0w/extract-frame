#include "opencv2/opencv.hpp"
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
using namespace cv;
int image_num = 0;

int main(int argc, char* argv[])
{
    printf("filename %s\n",argv[1]);
    cv::VideoCapture cap(0);

    if(!cap.isOpened())
    {
        return -1;
    }
    while(1){
        cv::Mat frame;
        cap >> frame;

        cv::imshow("window",frame);
        int key = cv::waitKey(1);
        if(key == 113)
        {
        break;
        }else if(key == 115)
        {
            cv::imwrite("img.png",frame);
        }
    }
    cv::destroyAllWindows();
    return 0;
}
