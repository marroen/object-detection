#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
  
  CascadeClassifier full_body;

  string full_body_path = "samples/haarcascade_fullbody.xml";
  full_body.load(full_body_path);

  string image_path = "images/people.jpg";
  Mat img = imread(image_path, IMREAD_GRAYSCALE);

  std::vector<Rect> bodies;
  full_body.detectMultiScale(img, bodies);

  // Need to highlight bodies with circle

  cout << "Bodies found: " << bodies.size() << "\n";
  
  for (size_t i = 0; i < bodies.size(); i++) {
    Point center(bodies[i].x + bodies[i].width/2, bodies[i].y + bodies[i].height/2);
    ellipse(img, center, Size(bodies[i].width/2, bodies[i].height/2), 0, 0, 360, Scalar(255, 0, 255), 4);
    Mat bodyROI = img(bodies[i]);
  }

  imshow("Display window", img);
  int k = waitKey(0);
  return 0;
}
