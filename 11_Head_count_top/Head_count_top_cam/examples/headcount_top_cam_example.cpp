#include <string>
#include <iostream>
#include "sample_app_headcount_top_cam.h"

using namespace std;


int32_t main(int32_t argc, char * argv[])
{
    /* Initialize the head count object*/
    HeadCountTop HC = HeadCountTop();

    /* Start the camera inference */
    HC.run_camera_inference();
    
    return 0;
}
