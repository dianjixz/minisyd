
#include <stdio.h>
#include "main.h"

// assets/image/565.bmp
// assets/image/888.bmp

#define _888_e

int main()
{
    image_t *img_ts = imlib_image_create(240, 240, PIXFORMAT_BINARY, 0, NULL, false);
    imlib_init_all();
#ifdef _888_e
                                    bmp_read(img_ts, "../../assets/image/888.bmp");
    imlib_draw_line(img_ts, 10, 10, 10, 100,        COLOR_R8_G8_B8_TO_RGB888(0xff, 0x00, 0x00), 4);
    imlib_draw_line(img_ts, 20, 10, 20, 100,        COLOR_R8_G8_B8_TO_RGB888(0x00, 0xff, 0x00), 4);
    imlib_draw_line(img_ts, 30, 10, 30, 100,        COLOR_R8_G8_B8_TO_RGB888(0x00, 0x00, 0xff), 4);
    imlib_draw_rectangle(img_ts, 10, 120, 14, 100,  COLOR_R8_G8_B8_TO_RGB888(0xff, 0x00, 0x00), 2, 0);
    imlib_draw_rectangle(img_ts, 26, 120, 14, 100,  COLOR_R8_G8_B8_TO_RGB888(0x00, 0x00, 0xff), 1, 1);
    imlib_draw_circle(img_ts, 70, 30, 20,           COLOR_R8_G8_B8_TO_RGB888(0x00, 0x00, 0xff), 2, false);
    imlib_draw_circle(img_ts, 70, 100, 20,          COLOR_R8_G8_B8_TO_RGB888(0x00, 0x00, 0xff), 2, true);
    imlib_draw_string(img_ts, 70, 150, "nihao",     COLOR_R8_G8_B8_TO_RGB888(0x00, 0x00, 0xff), 3.0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
#else
                                    bmp_read(img_ts, "../../assets/image/565.bmp");
    imlib_draw_line(img_ts, 10, 10, 10, 100,        COLOR_R8_G8_B8_TO_RGB565(0xff, 0x00, 0x00), 4);
    imlib_draw_line(img_ts, 20, 10, 20, 100,        COLOR_R8_G8_B8_TO_RGB565(0x00, 0xff, 0x00), 4);
    imlib_draw_line(img_ts, 30, 10, 30, 100,        COLOR_R8_G8_B8_TO_RGB565(0x00, 0x00, 0xff), 4);
    imlib_draw_rectangle(img_ts, 10, 120, 14, 100,  COLOR_R8_G8_B8_TO_RGB565(0xff, 0x00, 0x00), 2, 0);
    imlib_draw_rectangle(img_ts, 26, 120, 14, 100,  COLOR_R8_G8_B8_TO_RGB565(0x00, 0x00, 0xff), 1, 1);
    imlib_draw_circle(img_ts, 70, 30, 20,           COLOR_R8_G8_B8_TO_RGB565(0x00, 0x00, 0xff), 2, false);
    imlib_draw_circle(img_ts, 70, 100, 20,          COLOR_R8_G8_B8_TO_RGB565(0x00, 0x00, 0xff), 2, true);
    imlib_draw_string(img_ts, 70, 150, "nihao",     COLOR_R8_G8_B8_TO_RGB565(0x00, 0x00, 0xff), 3.0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
#endif
// (44, 80, 10, 110, -49, 115)

    image_t *arg_img = img_ts;

    list_t thresholds;
    list_init(&thresholds, sizeof(color_thresholds_list_lnk_data_t));

    color_thresholds_list_lnk_data_t tmp_ct;
    tmp_ct.LMin = 44;
    tmp_ct.AMin = 10;
    tmp_ct.BMin = -49;
    tmp_ct.LMax = 80;
    tmp_ct.AMax = 110;
    tmp_ct.BMax = 115;
    list_push_back(&thresholds, &tmp_ct);

    bool invert = false;

    rectangle_t roi;
    roi.x = 0;
    roi.y = 0;
    roi.w = 240;
    roi.h = 240;


    unsigned int x_stride = 2 ;
    unsigned int y_stride = 1;

    unsigned int area_threshold = 10;
    unsigned int pixels_threshold = 10;
    bool merge = false;
    int margin = 0;
    unsigned int x_hist_bins_max = 0;
    unsigned int y_hist_bins_max = 0;

    list_t out;
    fb_alloc_mark();

    imlib_find_blobs(&out, arg_img, &roi, x_stride, y_stride, &thresholds, invert,
            area_threshold, pixels_threshold, merge, margin,
            NULL, NULL, NULL, NULL, x_hist_bins_max, y_hist_bins_max);
    fb_alloc_free_till_mark();

    list_free(&thresholds);

    for (size_t i = 0; list_size(&out); i++) {
        find_blobs_list_lnk_data_t lnk_data;
        list_pop_front(&out, &lnk_data);
        printf("find ones!\n");
#ifdef _888_e
        imlib_draw_rectangle(img_ts, lnk_data.rect.x, lnk_data.rect.y, lnk_data.rect.w, lnk_data.rect.h, COLOR_R8_G8_B8_TO_RGB888(0x00, 0x00, 0x00), 1, 0);
#else
        imlib_draw_rectangle(img_ts, lnk_data.rect.x, lnk_data.rect.y, lnk_data.rect.w, lnk_data.rect.h, COLOR_R8_G8_B8_TO_RGB565(0x00, 0x00, 0x00), 1, 0);
#endif
    }
    

    // for (size_t i = 0; list_size(&out); i++) {
    //     find_blobs_list_lnk_data_t lnk_data;
    //     list_pop_front(&out, &lnk_data);

    //     lnk_data.corners[(FIND_BLOBS_CORNERS_RESOLUTION*0)/4].x;
    //     lnk_data.corners[(FIND_BLOBS_CORNERS_RESOLUTION*0)/4].y;
    //     lnk_data.corners[(FIND_BLOBS_CORNERS_RESOLUTION*1)/4].x;
    //     lnk_data.corners[(FIND_BLOBS_CORNERS_RESOLUTION*1)/4].y;
    //     lnk_data.corners[(FIND_BLOBS_CORNERS_RESOLUTION*2)/4].x;
    //     lnk_data.corners[(FIND_BLOBS_CORNERS_RESOLUTION*2)/4].y;
    //     lnk_data.corners[(FIND_BLOBS_CORNERS_RESOLUTION*3)/4].x;
    //     lnk_data.corners[(FIND_BLOBS_CORNERS_RESOLUTION*3)/4].y;
    //     point_t min_corners[4];
    //     point_min_area_rectangle(lnk_data.corners, min_corners, FIND_BLOBS_CORNERS_RESOLUTION);
        
    //     min_corners[0].x     min_corners[0].y
    //     min_corners[1].x     min_corners[1].y
    //     min_corners[2].x     min_corners[2].y
    //     min_corners[3].x     min_corners[3].y
    //     lnk_data.rect.x);
    //     lnk_data.rect.y);
    //     lnk_data.rect.w);
    //     lnk_data.rect.h);
    //     lnk_data.pixels);
    //     lnk_data.centroid_x);
    //     lnk_data.centroid_y);
    //     lnk_data.rotation);
    //     lnk_data.code);
    //     lnk_data.count);
    //     lnk_data.perimeter);
    //     lnk_data.roundness);
    //     lnk_data.x_hist_bins_count, NULL);
    //     lnk_data.y_hist_bins_count, NULL);

    //     for (int i = 0; i < lnk_data.x_hist_bins_count; i++) {
    //         lnk_data.x_hist_bins[i];
    //     }

    //     for (int i = 0; i < lnk_data.y_hist_bins_count; i++) {
    //         lnk_data.y_hist_bins[i];
    //     }

    //     if (lnk_data.x_hist_bins) xfree(lnk_data.x_hist_bins);
    //     if (lnk_data.y_hist_bins) xfree(lnk_data.y_hist_bins);
    // }







    
    bmp_write_subimg(img_ts, "./tmp.bmp",NULL);
    imlib_image_destroy(&img_ts);
    imlib_deinit_all();
    printf("hello\n");
    imlib_printf(5, "nihao imlib\n");
    return 0;
}
