#include "opencv2/opencv.hpp"
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
using namespace cv;
int image_num = 0;

void save_frame(Mat image);

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Error! This program require one file." << endl;
        return -1;
    }
//    printf("filename %s\n",argv[1]);
    
    Mat frame;
    VideoCapture video(argv[1]);
    if(!video.isOpened())
    {
        cout << "File cannot open." << endl;
        return -1;
    }
    int frame_num = 0;
    while(1){
//        cv::Mat frame;
        frame_num++; 
        video >> frame;
        if (frame.empty()){
            cout << "End of Video" << endl;
            break;
        }
        if (frame_num%50 == 0) save_frame(frame);

//        cv::imshow("window",frame);
//        int key = cv::waitKey(1);
//        if(key == 113)
//        {
//        break;
//        }else if(key == 115)
//        {
//            cv::imwrite("img.png",frame);
//        }
    }
//    cv::destroyAllWindows();
    return 0;
}

void save_frame(Mat image)
{
    stringstream name;
    name.str("");
    name << "image" << setw(5) << setfill('0') << image_num << ".png";
    imwrite(name.str(),image);
    image_num++;
}
