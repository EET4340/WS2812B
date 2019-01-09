
#ifndef WS2812B_H
#define	WS2812B_H

//Defines

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        unsigned char R;
        unsigned char G;
        unsigned char B;
    } RGB;
    
    void InitWS2812(void);
    void SetColor(RGB color, int numLED);
    void SetColors(RGB *colors, int numLED);

#ifdef	__cplusplus
}
#endif

#endif	/* WS2812B_H */

