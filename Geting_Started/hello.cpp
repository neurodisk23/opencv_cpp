#include <opencv2/opencv.hpp>

int main() {
    // Open the default camera (camera index 0)
    cv::VideoCapture cap(0);

    // Check if the camera opened successfully
    if (!cap.isOpened()) {
        std::cerr << "Error opening the camera" << std::endl;
        return -1;
    }

    // Set the camera frame width and height (optional)
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

    while (true) {
        // Capture a frame from the camera
        cv::Mat frame;
        cap >> frame;

        // Check if the frame was captured successfully
        if (frame.empty()) {
            std::cerr << "Error capturing frame" << std::endl;
            break;
        }

        // Display the captured frame
        cv::imshow("Camera Stream", frame);

        // Break the loop if the user presses the 'ESC' key
        if (cv::waitKey(1) == 27) {
            break;
        }
    }

    // Release the camera capture object
    cap.release();

    // Close all OpenCV windows
    cv::destroyAllWindows();

    return 0;
}

