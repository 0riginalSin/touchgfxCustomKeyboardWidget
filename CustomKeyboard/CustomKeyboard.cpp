/******************************************************************************
 * CustomKeyboard version 1.0
 * @file CustomKeyboard.cpp
 * @author 0riginalSin
 * @brief Contains class method implementation with comments.
 *
 * Keyboard with many sets of keys. Main point is to minimize quantity of
 * occupied memory. No using of std widgets, only HAL::lcd draw functions.
 *
 ******************************************************************************
 */

#include <gui/CustomKeyboard.hpp>
// #include <touchgfx/hal/HAL.hpp>

// #include <texts/TextKeysAndLanguages.hpp>
// #include <gui/screen1_screen/Screen1Presenter.hpp>
// #include <touchgfx/widgets/BoxWithBorder.hpp>
// #include <touchgfx/widgets/TextAreaWithWildcard.hpp>
// #include <gui/MyTextArea.hpp>
// #include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
namespace touchgfx
{
const Unicode::UnicodeChar CustomKeyboard::keyCharBuffer0_[KEYSET_SIZE] = {
    'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '\\', //start set
    'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', ';',
              'Z', 'X', 'C', 'V', 'B', 'N', 'M',
                            ' '
};
const Unicode::UnicodeChar CustomKeyboard::keyCharBuffer1_[KEYSET_SIZE] = {
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '\\', //shift set
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ':', ';',
              'z', 'x', 'c', 'v', 'b', 'n', 'm',
                            ' '
};
const Unicode::UnicodeChar CustomKeyboard::keyCharBuffer2_[KEYSET_SIZE] = {
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '@', //123 set
    '#', '$', '%', '&', '*', '-', '+', '(', ')', '!', '\"',
              '\'', ':', ';', '/', '?', ',', '.',
                            ' '
};
const Unicode::UnicodeChar CustomKeyboard::keyCharBuffer3_[KEYSET_SIZE] = {
    '~', 177, 215, 247, 8226, 186, 96, 180, '{', '}', 169, //123 + shift set
    163, 8364, '^', 174, 165, '_', '=', '[', ']', '<', '>',
              '!', 162, '|', '\\', '?', ',', '.',
                            ' '
};
const Unicode::UnicodeChar CustomKeyboard::controlKeysLabelBuffer_[CONTROL_KEYS_LABEL_BUFFER_SIZE] ={
    'S', 'H', 'T', '\0',
    'B', 'C', 'S', '\0',
    '1', '2', '3', '\0',
};

void CustomKeyboard::draw(const Rect& area) const{
    // Unicode::UnicodeChar character[] = { 'Q', 'T', 'A', 'T', 'B', 0 };
    // // touchgfx_printf( "%i ", sizeof(bwb) );
    // // if (typedText.hasValidId())
    // // {
    // //     const Font* fontToDraw = typedText.getFont();
    // //     if (fontToDraw != 0)
    // //     {
    // //         LCD::StringVisuals visuals(fontToDraw, color, alpha, typedText.getAlignment(), linespace, rotation, typedText.getTextDirection(), indentation, wideTextAction);
    // //         HAL::lcd().drawString(getAbsoluteRect(), area, visuals, character, 0, 0);
    // //     }
    // // }

    // LCD::StringVisuals visuals(FontManager::getFont(Typography::DEFAULT), touchgfx::Color::getColorFrom24BitRGB(0, 0, 0), 255, CENTER, 2, TEXT_ROTATE_0, TEXT_DIRECTION_LTR, 1);
    // // LCD::StringVisuals visuals;
    // // visuals.font = touchgfx::TypedText(T_STATICTEXT).getFont();
    // // visuals.alignment = CENTER;
    // // visuals.color = 0;
    // touchgfx::Rect keyArea(0, 0, 100, 30);
    // touchgfx::Rect invalidatedAreaRelative(0, 0, 100, 30);

    // HAL::lcd().fillRect(keyArea, touchgfx::Color::getColorFrom24BitRGB(235, 235, 235), 255);
    // HAL::lcd().drawString(keyArea, invalidatedAreaRelative, visuals, character, 0, 0);
    // keyArea.x = 30; keyArea.y = 0;
    // // Rect tmpRect(0, 0, 200, 30);
    // // invalidateRect(tmpRect);
    // HAL::lcd().drawString(keyArea, invalidatedAreaRelative, visuals, character, 0, 0);

    // uint16_t currWidth = 0;
    // uint16_t currHeight = 0;
    // uint8_t currentXGap = X_SIDE_GAP;
    // // uint16_t keyPossition_[KEYSET_SIZE * 2];
    // // for(uint8_t i = 0; i < KEYSET_SIZE; i++){
    // //     NewLine: //1 reference
    // //     if( (currWidth + 1)*KEY_WIDTH + X_GAP_BETWEEN_KEYS *currWidth + 2*currentXGap <= this->rect.width ){
    // //         keyPossition_[2 * i] = currentXGap + currWidth*(X_GAP_BETWEEN_KEYS + KEY_WIDTH);
    // //         keyPossition_[2 * i + 1] = stringBackgroundHeight_ + Y_SIDE_GAP + currHeight*(Y_GAP_BETWEEN_KEYS + KEY_HEIGHT);
    // //         currWidth++;
    // //     }
    // //     else if( (currHeight + 1)*KEY_HEIGHT + Y_GAP_BETWEEN_KEYS *currHeight + 2*Y_SIDE_GAP + stringBackgroundHeight_ <= this->rect.height ){
    // //         currHeight++;
    // //         currWidth = 0;
    // //         if(currHeight == 2){
    // //             currentXGap = X_SIDE_GAP_LASTROW;
    // //         }
    // //         goto NewLine;
    // //     }
    // // }
        // touchgfx_printf( "%i %i;", area.x, area.y );
        // touchgfx_printf( "%i %i |", area.width, area.height );
    
    //print string background
    touchgfx::Rect workArea(getX() + BORDER_SIZE, getY() + BORDER_SIZE, getWidth() - 2 * BORDER_SIZE,
     stringBackgroundHeight_ - 2 * BORDER_SIZE);
    touchgfx::Rect intersectToInvalidate;
    if( workArea.intersect(area) ){
        intersectToInvalidate = workArea & area;
        HAL::lcd().fillRect(intersectToInvalidate,
         touchgfx::Color::getColorFrom24BitRGB(255, 255, 255), 255);
    }
    //top border
    workArea.x = getX(); workArea.y = getY();
    workArea.width = getWidth(); workArea.height = BORDER_SIZE;
    if( workArea.intersect(area) ){
        intersectToInvalidate = workArea & area;
        HAL::lcd().fillRect(intersectToInvalidate, touchgfx::Color::getColorFrom24BitRGB(0, 0, 0), 255);
    }
    //bottom border
    workArea.x = getX(); workArea.y = stringBackgroundHeight_ - BORDER_SIZE;
     workArea.width = getWidth(); workArea.height = BORDER_SIZE;
    if( workArea.intersect(area) ){
        intersectToInvalidate = workArea & area;
        HAL::lcd().fillRect(intersectToInvalidate, touchgfx::Color::getColorFrom24BitRGB(0, 0, 0), 255);
    }
    //left border
    workArea.x = getX(); workArea.y = getY();
    workArea.width = BORDER_SIZE; workArea.height = stringBackgroundHeight_;
    if( workArea.intersect(area) ){
        intersectToInvalidate = workArea & area;
        HAL::lcd().fillRect(intersectToInvalidate, touchgfx::Color::getColorFrom24BitRGB(0, 0, 0), 255);
    }
    //right border
    workArea.x = getWidth() - BORDER_SIZE; workArea.y = getY();
    workArea.width = BORDER_SIZE; workArea.height = stringBackgroundHeight_;
    if( workArea.intersect(area) ){
        intersectToInvalidate = workArea & area;
        HAL::lcd().fillRect(intersectToInvalidate, touchgfx::Color::getColorFrom24BitRGB(0, 0, 0), 255);
    }
    
    //print keys background
    workArea.x = getX() + BORDER_SIZE; workArea.y = getY() + stringBackgroundHeight_;
    workArea.width = getWidth() - 2 * BORDER_SIZE;
    workArea.height = getHeight() - stringBackgroundHeight_ - BORDER_SIZE;
    if( workArea.intersect(area) ){
        intersectToInvalidate = workArea & area;
        HAL::lcd().fillRect(intersectToInvalidate,
         touchgfx::Color::getColorFrom24BitRGB(255, 255, 255), 255);
    } 
    // workArea.x = getX(); workArea.y = getY() + stringBackgroundHeight_ - BORDER_SIZE; workArea.width = getWidth(); workArea.height = BORDER_SIZE; //top border
    // if( workArea.intersect(area) ){
    //     intersectToInvalidate = workArea & area;
    //     HAL::lcd().fillRect(intersectToInvalidate, touchgfx::Color::getColorFrom24BitRGB(0, 0, 0), 255);
    // }
    
    //bottom border
    workArea.x = getX(); workArea.y = getHeight() - BORDER_SIZE;
    workArea.width = getWidth(); workArea.height = BORDER_SIZE;
    if( workArea.intersect(area) ){
        intersectToInvalidate = workArea & area;
        HAL::lcd().fillRect(intersectToInvalidate, touchgfx::Color::getColorFrom24BitRGB(0, 0, 0), 255);
    }
    //left border
    workArea.x = getX(); workArea.y = getY() + stringBackgroundHeight_;
    workArea.width = BORDER_SIZE; workArea.height = getHeight() - stringBackgroundHeight_;
    if( workArea.intersect(area) ){
        intersectToInvalidate = workArea & area;
        HAL::lcd().fillRect(intersectToInvalidate, touchgfx::Color::getColorFrom24BitRGB(0, 0, 0), 255);
    }
    //right border
    workArea.x = getWidth() - BORDER_SIZE; workArea.y = getY() + stringBackgroundHeight_;
    workArea.width = BORDER_SIZE; workArea.height = getHeight() - stringBackgroundHeight_;
    if( workArea.intersect(area) ){
        intersectToInvalidate = workArea & area;
        HAL::lcd().fillRect(intersectToInvalidate, touchgfx::Color::getColorFrom24BitRGB(0, 0, 0), 255);
    }

    //print string
    LCD::StringVisuals visuals(FontManager::getFont(Typography::DEFAULT),
     touchgfx::Color::getColorFrom24BitRGB(0, 0, 0), 255, LEFT, 0, TEXT_ROTATE_0, TEXT_DIRECTION_LTR, 1);
    workArea.x = getX() + BORDER_SIZE; workArea.y = getY();
    workArea.width = getWidth(); workArea.height = stringBackgroundHeight_;
    touchgfx::Rect invalidateArea(0, 0, getWidth(), stringBackgroundHeight_);
    if( workArea.intersect(area) ){
        intersectToInvalidate = workArea & area;
        HAL::lcd().drawString(intersectToInvalidate, invalidateArea, visuals, stringBuffer_, 0, 0);
    }

    //print keyset
    visuals.alignment = CENTER;
    touchgfx::Rect keyArea(keyPossition_[0], keyPossition_[1], KEY_WIDTH, KEY_HEIGHT);
    invalidateArea.width = KEY_WIDTH; invalidateArea.height = KEY_HEIGHT;
    Unicode::UnicodeChar ch[] = {0, 0};
    uint8_t i = 0;
    for(; i < KEYSET_SIZE -1; i++){ //-1 cause space button need special setup
        keyArea.x = keyPossition_[2 * i]; keyArea.y = keyPossition_[2 * i + 1];
        if( keyArea.intersect(area) ){
            intersectToInvalidate = keyArea & area;
        // touchgfx_printf( "%i %i;", intersectToInvalidate.x, intersectToInvalidate.y );
        // touchgfx_printf( "%i %i |", intersectToInvalidate.width, intersectToInvalidate.height );
            ch[0] = currentkeyCharBuffer_[i];
            if(i == highlightenKey_)
                HAL::lcd().fillRect(intersectToInvalidate,
                 touchgfx::Color::getColorFrom24BitRGB(130, 130, 130), 255);
            else
                HAL::lcd().fillRect(intersectToInvalidate,
                 touchgfx::Color::getColorFrom24BitRGB(235, 235, 235), 255);
            HAL::lcd().drawString(intersectToInvalidate, invalidateArea, visuals, ch, 0, 0);
        }
    }
    //print space button
    keyArea.x = keyPossition_[2 * i]; keyArea.y = keyPossition_[2 * i + 1];
    keyArea.width = SPACE_KEY_WIDTH; keyArea.height = SPACE_KEY_HEIGHT;
    if( keyArea.intersect(area) ){
        intersectToInvalidate = keyArea & area;
        // touchgfx_printf( "%i %i;", intersectToInvalidate.x, intersectToInvalidate.y );
        // touchgfx_printf( "%i %i |", intersectToInvalidate.width, intersectToInvalidate.height );
        if(i == highlightenKey_)
            HAL::lcd().fillRect(intersectToInvalidate,
             touchgfx::Color::getColorFrom24BitRGB(130, 130, 130), 255);
        else
            HAL::lcd().fillRect(intersectToInvalidate,
             touchgfx::Color::getColorFrom24BitRGB(235, 235, 235), 255);
    }
    i++;
    //print control keys
    for(; i < FULL_KEYSET_SIZE; i++){
        keyArea.x = keyPossition_[2 * i]; keyArea.y = keyPossition_[2 * i + 1];
        keyArea.width = C_KEY_WIDTH; keyArea.height = C_KEY_HEIGHT;
        if( keyArea.intersect(area) ){
            intersectToInvalidate = keyArea & area;
            invalidateArea.width = C_KEY_WIDTH; invalidateArea.height = C_KEY_HEIGHT;
            if(i == highlightenKey_)
                HAL::lcd().fillRect(intersectToInvalidate,
                 touchgfx::Color::getColorFrom24BitRGB(130, 130, 130), 255);
            else
                HAL::lcd().fillRect(intersectToInvalidate,
                 touchgfx::Color::getColorFrom24BitRGB(235, 235, 235), 255);
            HAL::lcd().drawString(intersectToInvalidate, invalidateArea,
             visuals, controlKeysLabelBuffer_ + (i - KEYSET_SIZE) * 4, 0, 0);
        }
    }
    // static long long iter = 0;
    // touchgfx_printf( "%i ;", tmp);
    // keyArea = touchgfx::Rect(keyPossition_[2 * tmp], keyPossition_[2 * tmp + 1], KEY_WIDTH, KEY_HEIGHT);
    // invalidateArea = touchgfx::Rect(0, 0, KEY_WIDTH, KEY_HEIGHT);
    // touchgfx_printf( "%i %i ;", keyArea.x, keyArea.y);
    // HAL::lcd().fillRect(keyArea, touchgfx::Color::getColorFrom24BitRGB(130, 130, 130), 255);
    // HAL::lcd().drawString(keyArea, invalidateArea, visuals, ch, 0, 0);
    // iter++;



}
uint8_t CustomKeyboard::getIdForCoordinates(uint16_t x, uint16_t y){
    uint8_t i = 0;
    //check if it's one of char-buttons
    for(; i < KEYSET_SIZE - 1; i++){
        if(x >= keyPossition_[2 * i] && x < keyPossition_[2 * i] + KEY_WIDTH &&
         y >= keyPossition_[2 * i + 1] && y < keyPossition_[2 * i + 1] + KEY_HEIGHT)
            return i;
    }
    //check if button is space
    if(x >= keyPossition_[2 * i] && x < keyPossition_[2 * i] + SPACE_KEY_WIDTH &&
     y >= keyPossition_[2 * i + 1] && y < keyPossition_[2 * i + 1] + SPACE_KEY_HEIGHT)
        return i;
    i++;
    //check if it's one of control-buttons
    for(; i < FULL_KEYSET_SIZE; i++){
        if(x >= keyPossition_[2 * i] && x < keyPossition_[2 * i] + C_KEY_WIDTH &&
         y >= keyPossition_[2 * i + 1] && y < keyPossition_[2 * i + 1] + C_KEY_HEIGHT)
            return i;
    }
    return i;
}

void CustomKeyboard::handleDragEvent(const DragEvent& evt){
    if(highlightenKey_ == UINT8_MAX)
        return;
    touchgfx::Rect keyArea;
    touchgfx_printf( "%i ", highlightenKey_);
    if(highlightenKey_ < KEYSET_SIZE - 1){
        keyArea.x = keyPossition_[2 * highlightenKey_]; keyArea.y = keyPossition_[2 * highlightenKey_ + 1];
        keyArea.width = KEY_WIDTH; keyArea.height =  KEY_HEIGHT;
    }
    else if(highlightenKey_ < KEYSET_SIZE){
        keyArea.x = keyPossition_[2 * highlightenKey_]; keyArea.y = keyPossition_[2 * highlightenKey_ + 1];
        keyArea.width = SPACE_KEY_WIDTH; keyArea.height = SPACE_KEY_HEIGHT;
    }
    else if(highlightenKey_ < FULL_KEYSET_SIZE){
        keyArea.x = keyPossition_[2 * highlightenKey_]; keyArea.y = keyPossition_[2 * highlightenKey_ + 1];
        keyArea.width = C_KEY_WIDTH; keyArea.height = C_KEY_HEIGHT;
    }
    if ( (!keyArea.intersect(static_cast<int16_t>(evt.getNewX()), static_cast<int16_t>(evt.getNewY()))) && (!cancelIsEmitted_) )
    {
        cancelIsEmitted_ = true;
        // Send a CANCEL click event, if user has dragged out of currently pressed/highlighted key.
        // ClickEvent cancelEvent(ClickEvent::CANCEL, static_cast<int16_t>(evt.getOldX()), static_cast<int16_t>(evt.getOldY()));
        // handleClickEvent(cancelEvent);
    }
    highlightenKey_ = UINT8_MAX;
    invalidateRect(keyArea);

}

void CustomKeyboard::handleClickEvent(const ClickEvent& evt){
    // touchgfx_printf( "%i %i;", evt.getX(), evt.getY() );
    // touchgfx_printf( "%i %i;", getX(), getY() );
    // touchgfx_printf( "%i %i |", getWidth(), getHeight() );
    // touchgfx::Color::getColorFrom24BitRGB(130, 130, 130);

    // touchgfx_printf( "%i ", getIdForCoordinates(evt.getX(), evt.getY()) );
    if (evt.getType() == ClickEvent::RELEASED && cancelIsEmitted_)
    {
        cancelIsEmitted_ = false;
        return;
    }
    uint8_t keyId = getIdForCoordinates(evt.getX(), evt.getY());
    if(keyId >= FULL_KEYSET_SIZE)
        return;
    // LCD::StringVisuals visuals(FontManager::getFont(Typography::DEFAULT), touchgfx::Color::getColorFrom24BitRGB(0, 0, 0), 255, CENTER, 0, TEXT_ROTATE_0, TEXT_DIRECTION_LTR, 1);
    touchgfx::Rect keyArea(keyPossition_[2 * keyId], keyPossition_[2 * keyId + 1], KEY_WIDTH, KEY_HEIGHT);
    if(keyId == KEYSET_SIZE - 1){ //if space button was clicked
        keyArea.width = SPACE_KEY_WIDTH; keyArea.height = SPACE_KEY_HEIGHT;
    }
    else if(keyId < FULL_KEYSET_SIZE){
        keyArea.width = C_KEY_WIDTH; keyArea.height = C_KEY_HEIGHT;
    }
    // touchgfx::Rect invalidateArea(0, 0, KEY_WIDTH, KEY_HEIGHT);
    
        // touchgfx_printf( "%i %i;", keyArea.x, keyArea.y );
        // touchgfx_printf( "%i %i |", keyArea.width, keyArea.height );
    // Unicode::UnicodeChar ch[] = {currentkeyCharBuffer_[keyId], 0};
    if(evt.getType() == ClickEvent::PRESSED){
        // touchgfx_printf( "%i ", keyId );
        // HAL::lcd().fillRect(keyArea, touchgfx::Color::getColorFrom24BitRGB(130, 130, 130), 255);
        // HAL::lcd().drawString(keyArea, invalidateArea, visuals, ch, 0, 0);
            highlightenKey_ = keyId;
            invalidateRect(keyArea);
    }
    else if(evt.getType() == ClickEvent::RELEASED){
        if(keyId < KEYSET_SIZE){
            highlightenKey_ = keyId;
            invalidateRect(keyArea);
            if(stringBufferPosition_ <= stringBufferSize_ - 2){ //-2: 1 char to add, 1 0-char
                // touchgfx_printf( "%i ",  stringBufferPosition_);
                stringBuffer_[stringBufferPosition_++] = currentkeyCharBuffer_[keyId];
                stringBuffer_[stringBufferPosition_] = '\0';
                keyArea.x = getX(); keyArea.y = getY();
                keyArea.width = getWidth(); keyArea.height = stringBackgroundHeight_;
                invalidateRect(keyArea);
            }
        }
        else if(keyId < FULL_KEYSET_SIZE){
            highlightenKey_ = keyId;
            invalidateRect(keyArea);
            switch(keyId){
                case KEYSET_SIZE: //shift
                    if(currentkeyCharBuffer_ == keyCharBuffer0_)
                        currentkeyCharBuffer_ = keyCharBuffer1_;
                    else if(currentkeyCharBuffer_ == keyCharBuffer1_)
                        currentkeyCharBuffer_ = keyCharBuffer0_;
                    else if(currentkeyCharBuffer_ == keyCharBuffer2_)
                        currentkeyCharBuffer_ = keyCharBuffer3_;
                    else if(currentkeyCharBuffer_ == keyCharBuffer3_)
                        currentkeyCharBuffer_ = keyCharBuffer2_;
                    keyArea.x = getX(); keyArea.y = stringBackgroundHeight_;
                    keyArea.width = getWidth(); keyArea.height = getHeight() - stringBackgroundHeight_;
                    invalidateRect(keyArea);
                break;
                case KEYSET_SIZE + 1: //backspace
                    if(stringBufferPosition_ != 0){
                        stringBuffer_[--stringBufferPosition_] = '\0';
                        keyArea.x = getX(); keyArea.y = getY();
                        keyArea.width = getWidth(); keyArea.height = stringBackgroundHeight_;
                        invalidateRect(keyArea);
                    }
                break;
                case KEYSET_SIZE + 2: //123
                    if(currentkeyCharBuffer_ == keyCharBuffer0_)
                        currentkeyCharBuffer_ = keyCharBuffer2_;
                    else if(currentkeyCharBuffer_ == keyCharBuffer1_)
                        currentkeyCharBuffer_ = keyCharBuffer3_;
                    else if(currentkeyCharBuffer_ == keyCharBuffer2_)
                        currentkeyCharBuffer_ = keyCharBuffer0_;
                    else if(currentkeyCharBuffer_ == keyCharBuffer3_)
                        currentkeyCharBuffer_ = keyCharBuffer1_;
                    keyArea.x = getX(); keyArea.y = stringBackgroundHeight_;
                    keyArea.width = getWidth(); keyArea.height = getHeight() - stringBackgroundHeight_;
                    invalidateRect(keyArea);
                break;

            }
        }    
        
        if(highlightenKey_ == keyId)
            highlightenKey_ = UINT8_MAX;
        invalidateRect(keyArea);
    }
}


int16_t MyTextArea::getTextHeight()
{
    return typedText.hasValidId() ? calculateTextHeight(typedText.getText(), 0, 0) : 0;
}

uint16_t MyTextArea::getTextWidth() const
{
    return typedText.hasValidId() ? typedText.getFont()->getStringWidth(typedText.getTextDirection(), typedText.getText(), 0, 0) : 0;
}

void MyTextArea::draw(const Rect& area) const
{
    Unicode::UnicodeChar character[] = { 'Q', 'T', 'A', 'T', 'B', 0 };
    // touchgfx_printf( "%i ", sizeof(bwb) );
    // if (typedText.hasValidId())
    // {
    //     const Font* fontToDraw = typedText.getFont();
    //     if (fontToDraw != 0)
    //     {
    //         LCD::StringVisuals visuals(fontToDraw, color, alpha, typedText.getAlignment(), linespace, rotation, typedText.getTextDirection(), indentation, wideTextAction);
    //         HAL::lcd().drawString(getAbsoluteRect(), area, visuals, character, 0, 0);
    //     }
    // }

    LCD::StringVisuals visuals(FontManager::getFont(Typography::DEFAULT), touchgfx::Color::getColorFrom24BitRGB(0, 0, 0), 255, CENTER, 2, TEXT_ROTATE_0, TEXT_DIRECTION_LTR, 1);
    // LCD::StringVisuals visuals;
    // visuals.font = touchgfx::TypedText(T_STATICTEXT).getFont();
    // visuals.alignment = CENTER;
    // visuals.color = 0;
    touchgfx::Rect keyArea(0, 0, 100, 30);
    touchgfx::Rect invalidatedAreaRelative(0, 0, 100, 30);

    HAL::lcd().drawString(keyArea, invalidatedAreaRelative, visuals, character, 0, 0);
    keyArea.x = 0; keyArea.y = 32;
    HAL::lcd().drawString(keyArea, invalidatedAreaRelative, visuals, character, 0, 0);
}

void MyTextArea::handleClickEvent(const ClickEvent& evt){
    // touchgfx_printf( "%i %i ;", evt.getX(), evt.getY() );
}

void MyTextArea::setTypedText(TypedText t)
{
    typedText = t;
    // If this MyTextArea does not yet have a width and height,
    // just assign the smallest possible size to fit current text.
    if (getWidth() == 0 && getHeight() == 0)
    {
        resizeToCurrentText();
    }
}

void MyTextArea::resizeToCurrentText()
{
    if (typedText.hasValidId())
    {
        uint16_t w = getTextWidth();
        uint16_t h = getTextHeight();
        if (rotation == TEXT_ROTATE_0 || rotation == TEXT_ROTATE_180)
        {
            setWidthHeight(w, h);
        }
        else
        {
            setWidthHeight(h, w);
        }
    }
}

void MyTextArea::resizeToCurrentTextWithAlignment()
{
    if (typedText.hasValidId())
    {
        Alignment alignment = typedText.getAlignment();
        uint16_t text_width = getTextWidth();
        uint16_t text_height = getTextHeight();
        if (rotation == TEXT_ROTATE_0 || rotation == TEXT_ROTATE_180)
        {
            // (rotate-0 && left-align) or (rotate-180 && right-align) places text to the left
            if (!((rotation == TEXT_ROTATE_0 && alignment == LEFT) || (rotation == TEXT_ROTATE_180 && alignment == RIGHT)))
            {
                uint16_t old_width = getWidth();
                uint16_t old_x = getX();
                if (alignment == CENTER)
                {
                    setX(old_x + (old_width - text_width) / 2);
                }
                else
                {
                    setX(old_x + (old_width - text_width));
                }
            }
            if (rotation == TEXT_ROTATE_180)
            {
                uint16_t old_height = getHeight();
                uint16_t old_y = getY();
                setY(old_y + (old_height - text_height));
            }
            setWidthHeight(text_width, text_height);
        }
        else
        {
            // 90+left or 270+right places text at the same y coordinate
            if (!((rotation == TEXT_ROTATE_90 && alignment == LEFT) || (rotation == TEXT_ROTATE_270 && alignment == RIGHT)))
            {
                uint16_t old_height = getHeight();
                uint16_t old_y = getY();
                if (alignment == CENTER)
                {
                    setY(old_y + (old_height - text_width) / 2);
                }
                else
                {
                    setY(old_y + (old_height - text_width));
                }
            }
            if (rotation == TEXT_ROTATE_90)
            {
                uint16_t old_width = getWidth();
                uint16_t old_x = getX();
                setX(old_x + (old_width - text_height));
            }
            setWidthHeight(text_height, text_width);
        }
    }
}

void MyTextArea::resizeHeightToCurrentText()
{
    if (typedText.hasValidId())
    {
        uint16_t h = getTextHeight();
        if (rotation == TEXT_ROTATE_0 || rotation == TEXT_ROTATE_180)
        {
            setHeight(h);
        }
        else
        {
            setWidth(h);
        }
    }
}

void MyTextArea::resizeHeightToCurrentTextWithRotation()
{
    if (typedText.hasValidId())
    {
        uint16_t h = getTextHeight();
        switch (rotation)
        {
        default:
        case TEXT_ROTATE_0:
            setHeight(h);
            break;
        case TEXT_ROTATE_90:
            setX(rect.right() - h);
            setWidth(h);
            break;
        case TEXT_ROTATE_180:
            setY(rect.bottom() - h);
            setHeight(h);
            break;
        case TEXT_ROTATE_270:
            setWidth(h);
            break;
        }
    }
}

int16_t MyTextArea::calculateTextHeight(const Unicode::UnicodeChar* format, ...) const
{
    if (!typedText.hasValidId())
    {
        return 0;
    }

    va_list pArg;
    va_start(pArg, format);

    const Font* fontToDraw = typedText.getFont();
    int16_t textHeight = fontToDraw->getMinimumTextHeight();

    TextProvider textProvider;
    textProvider.initialize(format, pArg, fontToDraw->getGSUBTable());

    int16_t numLines = LCD::getNumLines(textProvider, wideTextAction, typedText.getTextDirection(), typedText.getFont(), getWidth());

    va_end(pArg);
    return (textHeight + linespace > 0) ? (numLines * textHeight + (numLines - 1) * linespace) : (numLines > 0) ? (textHeight) : 0;
}
} // namespace touchgfx
