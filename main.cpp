/*
 * Copyright 12/06/2025 https://github.com/su8/0vervv
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]) {
  // Check if image path is provided
  if (argc < 2) { std::cerr << "Usage: " << argv[0] << " <image_path>" << std::endl; return EXIT_FAILURE; }

  std::string imagePath = argv[1];
  // Load the image
  cv::Mat image = cv::imread(imagePath, cv::IMREAD_UNCHANGED);

  // Validate if image is loaded
  if (image.empty()) { std::cerr << "Error: Could not open or find the image at: " << imagePath << std::endl; return EXIT_FAILURE; }

  // Create a resizable window
  cv::namedWindow("Image Viewer", cv::WINDOW_NORMAL);

  // Display the image
  cv::imshow("Image Viewer", image);

  std::cout << "Press any key to close the viewer..." << std::endl;

  // Wait indefinitely until a key is pressed
  cv::waitKey(0);

  return EXIT_SUCCESS;
}