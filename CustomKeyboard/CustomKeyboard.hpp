/******************************************************************************
 * CustomKeyboard version 1.0
 * @file CustomKeyboard.hpp
 * @author 0riginalSin
 * @brief Contains class declaration with comments.
 *
 * Keyboard with many sets of keys. Main point is to minimize quantity of
 * occupied memory. No using of std widgets, only HAL::lcd draw functions.
 *
 ******************************************************************************
 */

#ifndef CUSTOMKEYBOARD_HPP
#define CUSTOMKEYBOARD_HPP

#include <touchgfx/TypedText.hpp>
// #include <touchgfx/Unicode.hpp>
// #include <touchgfx/hal/Types.hpp>
// #include <touchgfx/lcd/LCD.hpp>
#include <touchgfx/widgets/Widget.hpp>
#include <fonts/ApplicationFontProvider.hpp>
#include <touchgfx/Color.hpp>

namespace touchgfx
{
#define KEYBOARD_WIDTH 320
#define KEYBOARD_HEIGHT 240
#define KEYSET_SIZE 30
#define KEY_WIDTH 24 //20
#define KEY_HEIGHT 30 //25
#define X_GAP_BETWEEN_KEYS 6
#define X_SIDE_GAP 12 //20
#define X_SIDE_GAP_LASTROW 72
#define Y_GAP_BETWEEN_KEYS 3
#define Y_SIDE_GAP 10

#define SPACE_KEY_WIDTH (5 * KEY_WIDTH + 4 * X_GAP_BETWEEN_KEYS) //228
#define SPACE_KEY_HEIGHT KEY_HEIGHT //25

#define CONTROL_KEYSET_SIZE 3
#define CONTROL_KEYS_LABEL_BUFFER_SIZE 12
#define FULL_KEYSET_SIZE (KEYSET_SIZE + CONTROL_KEYSET_SIZE)
#define C_KEY_WIDTH (2 * KEY_WIDTH + X_GAP_BETWEEN_KEYS) //46
#define C_KEY_HEIGHT KEY_HEIGHT //25

#define X_STRING_GAP 8
#define Y_STRING_GAP 8

#define BORDER_SIZE 2
/*
* @see Widget, Drawable
* The keyboard provides text input. Using the keyboard you need provide a buffer for input string.
* This is a minimize implementation of keyboard widget with no customizaton. If you need to customize
* button size, color or smth else you need to change draw method of this class. You need to use add
* function in class, where you need to have keyboard to be drawn.
*/
class CustomKeyboard : public Widget{
public:
    // CustomKeyboard() : Widget(), stringBackgroundHeight_(0),
    // stringBufferPosition_(0),
    // stringBufferSize_(0),
    // highlightenKey_(UINT8_MAX)
    // {
    //     touchable = true;
    // }

    /*
    * @brief Constructor. Take all parameters, needs to initialize fields, necessary for proper work.
    * @param stringBuffer Pointer to string to modify.
    * @param bufferSize Size of string buffer.
    * @param x X value in absulute cordinates.
    * @param y Y value in absolute cordinates.
    * @param width Width of keyboard.
    * @param height Height of keyboard.
    */
    CustomKeyboard(Unicode::UnicodeChar* stringBuffer, size_t bufferSize, int16_t x, int16_t y,
     int16_t width, int16_t height) : Widget(), stringBackgroundHeight_(0),
     currentkeyCharBuffer_(keyCharBuffer0_), stringBuffer_(stringBuffer),
     stringBufferPosition_( Unicode::strlen(stringBuffer_) ), stringBufferSize_(bufferSize),
     highlightenKey_(UINT8_MAX)
    {
        stringBackgroundHeight_ = FontManager::getFont(Typography::DEFAULT)->getMinimumTextHeight() * 2;
        // FontManager::getFont(Typography::DEFAULT)->getMaxTextHeight(stringBuffer_);
        Widget::setPosition(x, y, width, height);
        touchable = true;
        SetKeyPossition();
    }

    virtual ~CustomKeyboard() {}

    /*
    * @brief Overrides virtual function of Drawable. After invoking the container draw, the glyphs mapped to
    * keys are drawn and if a key has been pressed, it will be highlighted.
    * @param area Rectangle to be drawn.
    */
    virtual void draw(const Rect& area) const;

    virtual Rect getSolidRect() const
    {
        return Rect(0, 0, 0, 0);
    }

    /*
    * @brief Override the handleClickEvent on the container. The keyboard handles all click events
    * internally.
    * @param evt Parameter, that handles information about event.
    */
    virtual void handleClickEvent(const ClickEvent& evt);

    virtual void handleDragEvent(const DragEvent& evt);
    
    constexpr void SetKeyPossition(){
        // uint16_t currWidth = 0;
        // uint16_t currHeight = 0;
        // uint8_t currentXGap = X_SIDE_GAP;
        // uint8_t i = 0;
        // for(; i < KEYSET_SIZE; i++){
        //     if( (currWidth + 1)*KEY_WIDTH + X_GAP_BETWEEN_KEYS *currWidth + 2*currentXGap <= this->rect.width ){
        //         keyPossition_[2 * i] = currentXGap + currWidth*(X_GAP_BETWEEN_KEYS + KEY_WIDTH);
        //         keyPossition_[2 * i + 1] = stringBackgroundHeight_ + Y_SIDE_GAP + currHeight*(Y_GAP_BETWEEN_KEYS + KEY_HEIGHT);
        //         currWidth++;
        //     }
        //     else if( (currHeight + 1)*KEY_HEIGHT + Y_GAP_BETWEEN_KEYS *currHeight + 2*Y_SIDE_GAP + stringBackgroundHeight_ <= this->rect.height ){
        //         currHeight++;
        //         currWidth = 0;
        //         if(currHeight == 3){
        //             currentXGap = X_SIDE_GAP_LASTROW;
        //         }
        //         i--;
        //     }
        // }
        // //control keys
        // keyPossition_[2 * i] = X_SIDE_GAP; keyPossition_[2 * i++ + 1] = stringBackgroundHeight_ + Y_SIDE_GAP + (currHeight - 1)*(Y_GAP_BETWEEN_KEYS + SPACE_KEY_HEIGHT);
        // keyPossition_[2 * i] = KEYBOARD_WIDTH - X_SIDE_GAP - C_KEY_WIDTH; keyPossition_[2 * i++ + 1] = stringBackgroundHeight_ + Y_SIDE_GAP + (currHeight - 1)*(Y_GAP_BETWEEN_KEYS + SPACE_KEY_HEIGHT);
        // keyPossition_[2 * i] = X_SIDE_GAP; keyPossition_[2 * i++ + 1] = stringBackgroundHeight_ + Y_SIDE_GAP + (currHeight)*(Y_GAP_BETWEEN_KEYS + SPACE_KEY_HEIGHT);
        uint16_t currWidth = 0;
        uint16_t currHeight = 0;
        uint8_t currentXGap = X_SIDE_GAP;
        uint8_t i = 0;
        for(; i < KEYSET_SIZE; i++){
            if( (currWidth + 1)*KEY_WIDTH + X_GAP_BETWEEN_KEYS *currWidth + 2*currentXGap <= this->rect.width ){
                keyPossition_[2 * i] = currentXGap + currWidth*(X_GAP_BETWEEN_KEYS + KEY_WIDTH);
                keyPossition_[2 * i + 1] = stringBackgroundHeight_ + Y_SIDE_GAP + currHeight*(Y_GAP_BETWEEN_KEYS + KEY_HEIGHT);
                currWidth++;
            }
            else if( (currHeight + 1)*KEY_HEIGHT + Y_GAP_BETWEEN_KEYS *currHeight + 2*Y_SIDE_GAP + stringBackgroundHeight_ <= this->rect.height ){
                currHeight++;
                currWidth = 0;
                if(currHeight == 2){
                    currentXGap = X_SIDE_GAP_LASTROW;
                }
                i--;
            }
        }
        //control keys
        keyPossition_[2 * i] = X_SIDE_GAP; keyPossition_[2 * i++ + 1] = stringBackgroundHeight_ + Y_SIDE_GAP + (currHeight - 1)*(Y_GAP_BETWEEN_KEYS + KEY_HEIGHT);
        keyPossition_[2 * i] = KEYBOARD_WIDTH - 2 - X_SIDE_GAP - C_KEY_WIDTH; keyPossition_[2 * i++ + 1] = stringBackgroundHeight_ + Y_SIDE_GAP + (currHeight - 1)*(Y_GAP_BETWEEN_KEYS + KEY_HEIGHT);
        keyPossition_[2 * i] = X_SIDE_GAP; keyPossition_[2 * i++ + 1] = stringBackgroundHeight_ + Y_SIDE_GAP + (currHeight)*(Y_GAP_BETWEEN_KEYS + KEY_HEIGHT);
    }
protected:
    /*
    * @brief Find id of key from keyset using x, y coordinates from press event.
    * @param x X coordinate.
    * @param y Y coordinate.
    * @return Id, that is an ordinal num of key in keyCharBuffer.
    */
    uint8_t getIdForCoordinates(uint16_t x, uint16_t y);

    uint8_t stringBackgroundHeight_; //height of background, were the string would be drawn
    //buffer of consecutive x, y possitions of char-keys from keyset
    uint16_t keyPossition_[FULL_KEYSET_SIZE * 2];
    //buffer of labels for control keys
    static const Unicode::UnicodeChar controlKeysLabelBuffer_[CONTROL_KEYS_LABEL_BUFFER_SIZE];
    //buffers, that stores characters from char-buttons
    static const Unicode::UnicodeChar keyCharBuffer0_[KEYSET_SIZE];
    static const Unicode::UnicodeChar keyCharBuffer1_[KEYSET_SIZE];
    static const Unicode::UnicodeChar keyCharBuffer2_[KEYSET_SIZE];
    static const Unicode::UnicodeChar keyCharBuffer3_[KEYSET_SIZE];
    const Unicode::UnicodeChar* currentkeyCharBuffer_; //pointer to keyCharBuffer, that currently in use
    Unicode::UnicodeChar* stringBuffer_; //pointer to string to modify
    size_t stringBufferPosition_; //possition of cursor in the string
    size_t stringBufferSize_; //size of string buffer. 24 max in a row
    uint8_t highlightenKey_; //id of pressed key, that needs to be highlighten with a different color
    bool cancelIsEmitted_; //Is cancel emitted to check if key is realeased
};
/**
 * This widget is capable of showing a text area on the screen. The text must be a predefined
 * TypedText in the text sheet in the assets folder. In order to display a dynamic text,
 * use TextAreaWithOneWildcard or TextAreaWithTwoWildcards.
 *
 * @see TypedText, TextAreaWithOneWildcard, TextAreaWithTwoWildcards
 *
 * @note A MyTextArea just holds a pointer to the text displayed. The developer must ensure that
 *       the pointer remains valid when drawing.
 */
class MyTextArea : public Widget
{
public:
    MyTextArea()
        : Widget(), typedText(TYPED_TEXT_INVALID), color(0), linespace(0), alpha(255), indentation(0), rotation(TEXT_ROTATE_0), wideTextAction(WIDE_TEXT_NONE)
    {
        setTouchable(true);
        setVisible(true);
    }

    virtual Rect getSolidRect() const
    {
        return Rect(0, 0, 0, 0);
    }
    virtual void handleClickEvent(const ClickEvent& evt);
    /**
     * Sets the color of the text. If no color is set, the default color (black) is used.
     *
     * @param  color The color to use.
     */
    FORCE_INLINE_FUNCTION void setColor(colortype color)
    {
        this->color = color;
    }

    /**
     * Gets the color of the text. If no color has been set, the default color, black, is
     * returned.
     *
     * @return The color to used for drawing the text.
     */
    FORCE_INLINE_FUNCTION colortype getColor() const
    {
        return color;
    }

    /**
     * @copydoc Image::setAlpha
     */
    void setAlpha(uint8_t newAlpha)
    {
        alpha = newAlpha;
    }

    /**
     * @copydoc Image::getAlpha
     */
    uint8_t getAlpha() const
    {
        return alpha;
    }

    /**
     * Adjusts the MyTextArea y coordinate so the text will have its baseline at the specified
     * value. The placements is relative to the specified TypedText so if the TypedText is
     * changed, you have to set the baseline again.
     *
     * @param  baselineY The y coordinate of the baseline of the text.
     *
     * @note setTypedText() must be called prior to setting the baseline.
     */
    virtual void setBaselineY(int16_t baselineY)
    {
        setY(baselineY - getTypedText().getFont()->getFontHeight());
    }

    /**
     * Adjusts the MyTextArea x and y coordinates so the text will have its baseline at the
     * specified y value. The placements is relative to the specified TypedText so if the
     * TypedText is changed you have to set the baseline again. The specified x coordinate
     * will be used as the x coordinate of the MyTextArea.
     *
     * @param  x         The x coordinate of the MyTextArea.
     * @param  baselineY The y coordinate of the baseline of the text.
     *
     * @note setTypedText() must be called prior to setting the baseline.
     */
    virtual void setXBaselineY(int16_t x, int16_t baselineY)
    {
        setX(x);
        setBaselineY(baselineY);
    }

    /**
     * Sets the line spacing of the MyTextArea. Setting a larger value will increase the space
     * between lines. It is possible to set a negative value to have lines (partially)
     * overlap. Default line spacing, if not set, is 0.
     *
     * @param  space The line spacing of use in the MyTextArea.
     *
     * @see getLinespacing
     */
    FORCE_INLINE_FUNCTION void setLinespacing(int16_t space)
    {
        linespace = space;
    }

    /**
     * Gets the line spacing of the MyTextArea. If no line spacing has been set, the line
     * spacing is 0.
     *
     * @return The line spacing.
     *
     * @see setLinespacing
     */
    FORCE_INLINE_FUNCTION int16_t getLinespacing() const
    {
        return linespace;
    }

    /**
     * Sets the indentation for the text. This can be very useful when a font is an italic
     * font where letters such as "j" and "g" extend a lot to the left under the previous
     * character(s). if a line starts with a "j" or "g" this letter would either have to be
     * pushed to the right to be able to see all of it, e.g. using spaces (which would ruin
     * a multi line text which is left aligned) - or by clipping the first letter (which
     * could ruin the nice graphics). The solution is to change
     * @code
     *      MyTextArea.setPosition(50, 50, 100, 100);
     * @endcode
     * to
     * @code
     *      MyTextArea.setPosition(45, 50, 110, 100);
     *      MyTextArea.setIndentation(5);
     * @endcode
     * Characters that do not extend to the left under the previous characters will be drawn
     * in the same position in either case, but "j" and "g" will be aligned with other lines.
     *
     * The function Font::getMaxPixelsLeft() will give you the maximum number of pixels any glyph
     * in the font extends to the left.
     *
     * @param  indent The indentation from left (when left aligned text) and right (when right
     *                aligned text).
     *
     * @see Font::getMaxPixelsLeft
     */
    FORCE_INLINE_FUNCTION void setIndentation(uint8_t indent)
    {
        indentation = indent;
    }

    /**
     * Gets the indentation of text inside the MyTextArea.
     *
     * @return The indentation.
     *
     * @see setIndentation
     */
    FORCE_INLINE_FUNCTION uint8_t getIndentation()
    {
        return indentation;
    }

    /**
     * Gets the total height needed by the text, taking number of lines and line spacing
     * into consideration.
     *
     * @return the total height needed by the text.
     */
    virtual int16_t getTextHeight();

    /**
     * Gets the width in pixels of the current associated text in the current selected
     * language. In case of multi-lined text the width of the widest line is returned.
     *
     * @return The width in pixels of the current text.
     */
    virtual uint16_t getTextWidth() const;

    virtual void draw(const Rect& area) const;

    /**
     * Sets the TypedText of the text area. If no prior size has been set, the MyTextArea will
     * be resized to fit the new TypedText.
     *
     * @param  t The TypedText for this widget to display.
     *
     * @see resizeToCurrentText
     */
    void setTypedText(TypedText t);

    /**
     * Gets the TypedText of the text area.
     *
     * @return The currently used TypedText.
     */
    TypedText getTypedText() const
    {
        return typedText;
    }

    /**
     * Sets rotation of the text in the MyTextArea. The value TEXT_ROTATE_0 is the default for
     * normal text. The value TEXT_ROTATE_90 will rotate the text clockwise, thus writing
     * from the top of the display and down. Similarly TEXT_ROTATE_180 and TEXT_ROTATE_270
     * will each rotate the text further 90 degrees clockwise.
     *
     * @param  rotation The rotation of the text.
     */
    void setRotation(const TextRotation rotation)
    {
        this->rotation = rotation;
    }

    /**
     * Gets rotation of the text in the MyTextArea.
     *
     * @return The rotation of the text.
     *
     * @see setRotation
     */
    TextRotation getRotation() const
    {
        return rotation;
    }

    /**
     * Sets the dimensions of the MyTextArea to match the width and height of the current
     * associated text for the current selected language.
     *
     * If WordWrap is turned on for the MyTextArea, the height might be set to an unexpected
     * value, as only manually insert line breaks in the text will be respected - use
     * resizeHeightToCurrentText() to keep the width of the MyTextArea and therefore retain
     * word wrapping.
     *
     * If the text is centered or right aligned, calling resizeToCurrentText() will actually
     * move the text on the screen, as the x and y coordinates of the MyTextArea widget is not
     * changed. To simply minimize the size of the MyTextArea but keep the TypedText in the
     * same position on the screen, use resizeToCurrentTextWithAlignment(). This is also the
     * case if the text is rotated, e.g. 180 degrees.
     *
     * @see setRotation, resizeHeightToCurrentText
     *
     * @note If the current text rotation is either 90 or 270 degrees, the width of the text area
     *       will be set to the height of the text and vice versa, as the text is rotated.
     */
    void resizeToCurrentText();

    /**
     * Sets the dimensions of the MyTextArea to match the width and height of the current
     * associated text for the current selected language, and for centered and right aligned
     * text, the position of the MyTextArea widget is also updated to keep the text in the
     * same position on the display. Text that is rotated is also handled properly.
     *
     * @see setRotation, resizeHeightToCurrentText
     *
     * @note If the current text rotation is either 90 or 270 degrees, the width of the text area
     *       will be set to the height of the text and vice versa, as the text is rotated.
     */
    void resizeToCurrentTextWithAlignment();

    /**
     * Sets the height of the MyTextArea to match the height of the current associated text
     * for the current selected language. This is especially useful for texts with WordWrap
     * enabled.
     *
     * @see resizeToCurrentText, setWideTextAction, setRotation,
     *      resizeHeightToCurrentTextWithRotation
     *
     * @note If the current text rotation is either 90 or 270 degrees, the width of the text area
     *       will be set and not the height, as the text is rotated.
     * @note If the current text is rotated, the x/y coordinate is not updated, which means that
     *       the text will be repositioned on the display.
     */
    void resizeHeightToCurrentText();

    /**
     * Sets the height of the MyTextArea to match the height of the current associated text
     * for the current selected language. This is especially useful for texts with WordWrap
     * enabled.
     *
     * @see resizeToCurrentText, setWideTextAction, setRotation, resizeHeightToCurrentText
     *
     * @note If the current text rotation is either 90 or 270 degrees, the width of the text area
     *       will be set and not the height, as the text is rotated. Also, the x or y
     *       coordinates will be updated.
     */
    void resizeHeightToCurrentTextWithRotation();

    /**
     * Defines what to do if a line of text is wider than the text area. Default action is
     * ::WIDE_TEXT_NONE which means that text lines are only broken if there is a manually
     * inserted newline in the text.
     *
     * If wrapping is enabled and the text would occupy more lines than the size of the
     * MyTextArea, the end of the last line will get an ellipsis (often &hellip;) to signal
     * that some text is missing. The character used for ellipsis is taken from the text
     * spreadsheet.
     *
     * @param  action The action to perform for wide lines of text.
     *
     * @see WideTextAction, getWideTextAction, resizeHeightToCurrentText
     */
    void setWideTextAction(WideTextAction action)
    {
        wideTextAction = action;
    }

    /**
     * Gets wide text action previously set using setWideTextAction.
     *
     * @return current WideTextAction setting.
     *
     * @see setWideTextAction, WideTextAction
     */
    WideTextAction getWideTextAction() const
    {
        return wideTextAction;
    }

    /**
     * Gets the total height needed by the text. Determined by number of lines and
     * linespace. The number of parameters passed after the format, must match the number of
     * wildcards in the TypedText.
     *
     * @param  format The text containing &lt;placeholder> wildcards.
     * @param  ...    Variable arguments providing additional information.
     *
     * @return the total height needed by the text.
     */
    virtual int16_t calculateTextHeight(const Unicode::UnicodeChar* format, ...) const;

protected:
    TypedText typedText;           ///< The TypedText to display
    colortype color;               ///< The color to use for the text.
    int16_t linespace;             ///< The extra space between lines of text, measured in pixels.
    uint8_t alpha;                 ///< The alpha to use.
    uint8_t indentation;           ///< The indentation of the text inside the text area.
    TextRotation rotation;         ///< The text rotation to use in steps of 90 degrees.
    WideTextAction wideTextAction; ///< What to do if the lines of text are wider than the text area.
};

} // namespace touchgfx

#endif // CUSTOMKEYBOARD_HPP
