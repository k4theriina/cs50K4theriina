#include "helpers.h"
#include <math.h>

int check255 (int rgbColor);
int avgRGB(int a, int b, int c, int d, int f, int g, int h, int i);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // loop over every pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // take average RGB triple of the pixel
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            // Change pixel value to that value for each RGB
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute sepia values
            int sepiaRed = check255(round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue));
            int sepiaGreen = check255(round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue));
            int sepiaBlue = check255(round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue));
            // Update pixel with sepia values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer;
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels
            buffer = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;
            float totalPixels = 0;

            // loop over all neighboring pixels
            for (int updated_i = i - 1; updated_i <= i + 1; updated_i++)
            {
                for (int updated_j = j - 1; updated_j <= j + 1; updated_j++)
                {
                    // adds the RGB values to its respective totals only if the pixel is in bounds
                    if (updated_i >= 0 && updated_j >= 0 && updated_i < height && updated_j < width)
                    {
                        totalRed += copy[updated_i][updated_j].rgbtRed;
                        totalGreen += copy[updated_i][updated_j].rgbtGreen;
                        totalBlue += copy[updated_i][updated_j].rgbtBlue;
                        totalPixels++;
                    }
                }
            }
            // changes the pixel into the average
            image[i][j].rgbtRed = round(totalRed / totalPixels);
            image[i][j].rgbtGreen = round(totalGreen / totalPixels);
            image[i][j].rgbtBlue = round(totalBlue / totalPixels);
        }
    }

    return;
}

int check255(int rgbColor)
{
    if (rgbColor > 255)
    {
        return 255;
    }
    else
    {
        return rgbColor;
    }
}

/*int avgRGB(int a, int b, int c, int d, int f, int g, int h, int i)
{
    int average = round((a.rgbtRed + a.rgbtGreen + a.rgbtBlue) / 3.0);
    for (int i = 0; i < 8; i++)
    {
        int averageRGB =a [0]
    }
    int averageBlur =
}
*/
