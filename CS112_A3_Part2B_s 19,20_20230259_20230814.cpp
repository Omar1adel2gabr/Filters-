//Name: Omar adel gabr                        ID:20230259    S:19,20      Did :merge_two_image,converting_image_gray,Darken_and_lightnes_image,converting_image_purple,detect_image_edge(ApplySobelOperator,ConvertToGrayscale)

//Name: saif eddin wassem hussein abu mustafa ID:20230814    S:19,20      Did :invert_image,rotate_image,frame ,samurai,blur



// All test cases had done by (photo.jpg) 
#include <iostream>
using namespace std;
#include "Image_Class.h"
#include <vector>






void merge_two_image() {
    string filename, filename_two, filename_three;
    cout << " 1:Pls enter colored image name to turn to mix: ";
    cin >> filename;
    cout << " 2:Pls enter colored image name to turn to mix : ";
    cin >> filename_two;

    Image image(filename);
    Image image_two(filename_two);
    //check which photo bigger this to handle if image 2 bigger
    if (image.width < image_two.width || image.height < image_two.height) {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                //merge the photo pixel by pixel
                image(i, j, 0) = (image_two(i, j, 0) + image(i, j, 0)) / 2;
                image(i, j, 1) = (image_two(i, j, 1) + image(i, j, 1)) / 2;
                image(i, j, 2) = (image_two(i, j, 2) + image(i, j, 2)) / 2;

            }
        }
        cout << "Pls enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        cin >> filename_three;
        image.saveImage(filename_three);

    }
    //this if one bigger
    if (image.width > image_two.width || image.height > image_two.height) {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {

                image(i, j, 0) = (image_two(i, j, 0) + image(i, j, 0)) / 2;
                image(i, j, 1) = (image_two(i, j, 1) + image(i, j, 1)) / 2;
                image(i, j, 2) = (image_two(i, j, 2) + image(i, j, 2)) / 2;

            }
        }
        cout << "Pls enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        cin >> filename_three;
        image.saveImage(filename_three);
    }

    //this if two equal one
    if (image.width == image_two.width || image.height == image_two.height) {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {

                image(i, j, 0) = (image_two(i, j, 0) + image(i, j, 0)) / 2;
                image(i, j, 1) = (image_two(i, j, 1) + image(i, j, 1)) / 2;
                image(i, j, 2) = (image_two(i, j, 2) + image(i, j, 2)) / 2;

            }
        }
        cout << "Pls enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        cin >> filename_three;
        image.saveImage(filename_three);

    }
}



void converting_image_gray() {
    string filename;
    cout << "Pls enter colored image name to turn to gray scale: ";
    cin >> filename;

    Image image(filename);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0; // Initialize average value

            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k); // Accumulate pixel values
            }

            avg /= 3; // Calculate average

            // Set all channels to the average value
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);
}

void Darken_and_lightnes_image() {


    int choice;
    string filename;
    cout << "Pls enter colored image name to control about lighten: ";
    cin >> filename;
    cout << " what do you want ? \n1)brigh by 50%\n2)dark by 50%\n";
    cin >> choice;
    Image image(filename);
    if (choice == 2) {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {


                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = image(i, j, k) * .5; // Accumulate pixel values
                }




            }
        }

        cout << "Pls enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        cin >> filename;
        image.saveImage(filename);
    }

    if (choice == 1) {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {


                for (int k = 0; k < 3; ++k) {
                    int newValue = image(i, j, k) * 1.5;
                    // Clamp the new value to be between 0 and 255
                    image(i, j, k) = min(newValue, 255);
                }
            }
        }

        cout << "Pls enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        cin >> filename;
        image.saveImage(filename);
    }
}

void invert_image() {
    string inputFilename, outputFilename;
    cout << "Please enter the input image name for inversion: ";
    cin >> inputFilename;


    Image image(inputFilename);


    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {

            for (int k = 0; k < 3; ++k) {
                unsigned char originalColor = image(i, j, k);
                unsigned char invertedColor = 255 - originalColor;
                image(i, j, k) = invertedColor;
            }
        }
    }

    cout << "Please enter the output image name (include extension .jpg, .bmp, .png, .tga): ";
    cin >> outputFilename;
    image.saveImage(outputFilename);

    cout << "Inversion complete. Image saved as " << outputFilename << endl;

}





void ConvertToGrayscale(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0; // Initialize average value

            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k); // Accumulate pixel values
            }

            avg /= 3; // Calculate average

            // Set all channels to the average value
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
}

// Function to apply the Sobel operator to detect edges
void ApplySobelOperator(Image& image, Image& edgeImage) {
    // Sobel X and Y kernels
    int Gx[3][3] = { {-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1} };
    int Gy[3][3] = { {-1, -2, -1}, {0, 0, 0}, {1, 2, 1} };

    // Apply the Sobel kernels to each pixel (excluding the border pixels)
    for (int i = 1; i < image.width - 1; ++i) {
        for (int j = 1; j < image.height - 1; ++j) {
            int sumX = 0;
            int sumY = 0;

            // Apply the Sobel kernels to the pixel and its neighbors
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    sumX += image.getPixel(i + k, j + l, 0) * Gx[k + 1][l + 1]; // Assuming getPixel method
                    sumY += image.getPixel(i + k, j + l, 0) * Gy[k + 1][l + 1];
                }
            }

            // Calculate the magnitude of the gradient
            int magnitude = static_cast<int>(sqrt(sumX * sumX + sumY * sumY));
            magnitude = (magnitude < 255) ? 255 : magnitude; // Clamp the value

            // Set the pixel value in the edge image
            edgeImage.setPixel(i, j, 0, magnitude); // Assuming setPixel method
            edgeImage.setPixel(i, j, 1, magnitude);
            edgeImage.setPixel(i, j, 2, magnitude);
        }
    }

}

void converting_image_purple() {
    string filename;
    cout << "Pls enter colored image name to turn to purple scale: ";
    cin >> filename;

    Image image(filename);

    // Define purple color values
    const unsigned char purple[] = { 128,0,128 }; // Red component for purple


    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {




            // Set the pixel to a shade of purple based on the average brightness
            image(i, j, 0) = (image(i, j, 0) * purple[0]) / 255;
            image(i, j, 1) = (image(i, j, 1) * purple[1]) / 255;
            image(i, j, 2) = (image(i, j, 2) * purple[2]) / 255;
        }
    }

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);
}


vector<unsigned char> rotateImage(const unsigned char* imageData, int& width, int& height, const int channels, const int angle) {
    int newWidth = angle == 180 ? width : height;
    int newHeight = angle == 180 ? height : width;
    vector<unsigned char> rotatedImage(newWidth * newHeight * channels);

    for (int y = 0; y < newHeight; ++y) {
        for (int x = 0; x < newWidth; ++x) {
            for (int c = 0; c < channels; ++c) {
                int oldX, oldY;
                switch (angle) {
                case 90:
                    oldX = height - 1 - y;
                    oldY = x;
                    break;
                case 180:
                    oldX = width - 1 - x;
                    oldY = height - 1 - y;
                    break;
                case 270:
                    oldX = y;
                    oldY = width - 1 - x;
                    break;
                }
                rotatedImage[(y * newWidth + x) * channels + c] = imageData[(oldY * width + oldX) * channels + c];
            }
        }
    }

    if (angle != 180) {
        swap(width, height);
    }
    return rotatedImage;
}
int rotate_image() {
    string inputPath;
    string outputPath;

    cout << "Enter image ";
    cin >> inputPath;
    cout << "Enter the way that you need to output the image ";
    cin >> outputPath;

    int width, height, channels;
    unsigned char* imageData = stbi_load(inputPath.c_str(), &width, &height, &channels, 0);

    if (!imageData) {
        cerr << "Failed to load image\n";
        return 1;
    }

    cout << "Enter rotation angle (90, 180, 270): ";
    int angle;
    cin >> angle;

    if (angle != 90 && angle != 180 && angle != 270) {
        cerr << "Invalid rotation angle\n";
        stbi_image_free(imageData);
        return 1;
    }

    auto rotatedImageData = rotateImage(imageData, width, height, channels, angle);
    if (!stbi_write_png(outputPath.c_str(), width, height, channels, rotatedImageData.data(), width * channels)) {
        cerr << "Failed to save rotated image\n";
    }
    else {
        cout << "Rotated image saved successfully to " << outputPath << "\n";
    }

    stbi_image_free(imageData);
}


int frame() {
    std::string inputFilename;
    std::cout << "Enter image ";
    std::cin >> inputFilename;


    int width, height, channels;
    unsigned char* originalImage = stbi_load(inputFilename.c_str(), &width, &height, &channels, 0);
    if (originalImage == NULL) {
        std::cerr << "Error loading image from '" << inputFilename << "'\n";
        return 1;
    }


    int frameThickness = 10;
    unsigned char frameColor[3] = { 255, 0, 0 };


    int newWidth = width + 2 * frameThickness;
    int newHeight = height + 2 * frameThickness;


    size_t newImageSize = newWidth * newHeight * channels;
    unsigned char* newImage = new unsigned char[newImageSize];
    if (newImage == NULL) {
        std::cerr << "Memory allocation failed\n";
        stbi_image_free(originalImage);
        return 1;
    }


    for (int y = 0; y < newHeight; ++y) {
        for (int x = 0; x < newWidth; ++x) {
            int idx = (y * newWidth + x) * channels;
            if (x < frameThickness || y < frameThickness || x >= newWidth - frameThickness || y >= newHeight - frameThickness) {
                memcpy(newImage + idx, frameColor, channels);
            }
            else {
                int origIdx = ((y - frameThickness) * width + (x - frameThickness)) * channels;
                memcpy(newImage + idx, originalImage + origIdx, channels);
            }
        }
    }


    std::string outputFilename;
    std::cout << "Enter the way that you need to output the image ";
    std::cin >> outputFilename;


    if (!stbi_write_png(outputFilename.c_str(), newWidth, newHeight, channels, newImage, newWidth * channels)) {
        std::cerr << "Error saving image to '" << outputFilename << "'\n";
    }


    stbi_image_free(originalImage);
    delete[] newImage;

}

int samurai() {
    int width, height, channels;
    string inputFilename, outputFilename;


    cout << "Enter image ";
    cin >> inputFilename;


    unsigned char* data = stbi_load(inputFilename.c_str(), &width, &height, &channels, 0);
    if (data == nullptr) {
        cerr << "Error: Could not load the image." << endl;
        return -1;
    }
    else {
        cout << "Image loaded successfully" << width << "x" << height << ", Channels: " << channels << endl;
    }


    for (int i = 0; i < width * height * channels; i += channels) {
        data[i] = 230;
        if (channels > 1) {
            data[i + 1] = 255 - data[i + 1];
            data[i + 2] = 255 - data[i + 2];
        }

    }

    cout << "Enter the way that you need to output the image ";
    cin >> outputFilename;


    if (!stbi_write_png(outputFilename.c_str(), width, height, channels, data, width * channels)) {
        cerr << "Error: Could not write the image." << endl;
        stbi_image_free(data);
        return -1;
    }
    else {
        cout << "The color adjusted image has been successfully saved as " << outputFilename << endl;
    }


    stbi_image_free(data);
}



void simpleBlur(unsigned char* img, int width, int height, int channels) {
    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            for (int c = 0; c < channels; ++c) {
                int sum = 0;

                for (int ky = -1; ky <= 1; ky++) {
                    for (int kx = -1; kx <= 1; kx++) {
                        int pixelIndex = ((y + ky) * width + (x + kx)) * channels + c;
                        sum += img[pixelIndex];
                    }
                }
                img[(y * width + x) * channels + c] = sum / 9;
            }
        }
    }
}
int blur() {
    string inputPath, outputPath;
    cout << "Enter image ";
    cin >> inputPath;
    cout << "Enter the way that you need to output the image";
    cin >> outputPath;

    int width, height, channels;
    unsigned char* imageData = stbi_load(inputPath.c_str(), &width, &height, &channels, 0);
    if (imageData == nullptr) {
        cerr << "Failed to load image\n";
        return -1;
    }


    int numberOfPasses = 3;
    for (int i = 0; i < numberOfPasses; ++i) {
        simpleBlur(imageData, width, height, channels);
    }

    if (!stbi_write_png(outputPath.c_str(), width, height, channels, imageData, width * channels)) {
        cerr << "Failed to save blurred image\n";
        stbi_image_free(imageData);
        return -1;
    }

    stbi_image_free(imageData);
    cout << "Blurred image saved successfully to " << outputPath << "\n";
}







int main() {


    while (true) {
        int n;
        cout << "welcome to filter program\n";
        cout << " which filter do you want?\n1)merge.\n2)convert to gray.\n3)darken and light image\n4)invert image\n5)detect edge \n6)convert to purple\n7)rotate image\n8)add frame\n9)samurai\n10)blur\n";

        cin >> n;
        if (n == 1) {
            merge_two_image();
        }
        if (n == 2) {
            converting_image_gray();
        }
        if (n == 3) {
            Darken_and_lightnes_image();
        }
        if (n == 4) {
            invert_image();
        }

        if (n == 5) {
            string filename;
            cout << "Please enter the colored image name to detect edge : ";
            cin >> filename;

            // Load the image
            Image image(filename);

            // Convert the image to grayscale
            ConvertToGrayscale(image);

            // Create a new image to store the edge information
            Image edgeImage(image.width, image.height); // Assuming Image_Class has a constructor for dimensions

            // Apply the Sobel operator to detect edges
            ApplySobelOperator(image, edgeImage);

            cout << "Enter the name to save the edge-detected image (including file extension): ";
            cin >> filename;

            // Save the edge-detected image
            edgeImage.saveImage(filename);

        }
        if (n == 6) {
            converting_image_purple();
        }
        if (n == 7) {
            rotate_image();
        }
        if (n == 8) {
            frame();
        }
        if (n == 9) {
            samurai();
        }
        if (n == 10) {
            blur();
        }
        cout << " what do you want\n 1)try another filter\n2)exite\n ";
        int k;
        cin >> k;
        if (k == 1) {}
        else
            break;
    }
    return 0;
}