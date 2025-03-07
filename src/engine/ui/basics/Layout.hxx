#ifndef LAYOUT_HXX_
#define LAYOUT_HXX_
#include "UIElement.hxx"

#include <string>
#include <vector>

struct LayoutData
{
  std::string alignment;             ///< <mandatory> where the element should be placed. e.g. CENTER
  std::string layoutType;            ///< <mandatory> how to layout, default = HORIZONTAL
  std::string layoutParentElementID; ///< elementID of the parent UiElement this group should be aligned to.
  float alignmentOffset = 0.0F;      ///< Offset in percent to the screen point. can be negative
  int padding = 0;                   ///< padding between elements in pixels
  int paddingToParent = 0;           ///< padding between this group and the parent in pixels
  int groupHeight = 0;               ///< <internal> height of all elements in group
  int groupWidth = 0;                ///< <internal> Width of all elements in group
  uint32_t fontSize = 20;             ///< <internal> default font size of all elements in group
};

/**
 * @class Layout
 * @brief Layout functionality
 * @details Parses the layout parameters from UiLayout and also adds elements to the buildings menu
 * Buttons from UiLayout.json are added as "main buttons" for certain categories.
 * All tiles from TileData.json that are in specific categories will be added to this group automatically. The "icon" parameter serves as image for the corresponding ImageButton.
 * All tiles that are not in certain categories will be added to the Debug Menu, which is only shown if Debug Mode has been enabled.
 * @note this is a static class and can not be instantiated.
 */
class Layout
{
public:
  /**
 * @brief Arrange the layout elements
 */
  static void arrangeElements();

private:
  /**
 * @brief Construct a new Menu Group Build object
 */
  Layout() = default;
  /**
 * @brief Destroy the Layout object
 */
  ~Layout() = default;

  /**
* @brief Arrange Elements that are aligned to a parent
* @details This is a seperate function, so it can recurse if a parent element has a parent, so we can be sure that everything is initialized properly. 
* @param groupLayout LayoutData from the group that should be layouted
* @param groupElements Elements of the group that should be layouted
*/
  static void arrangeChildElements(LayoutData &groupLayout, std::vector<UIElement *> groupElements);

  /**
* @brief Calculates height and width of layout groups
* @details Calculates layout group dimensions and updates groupHeight and groupWidth in LayoutData struct
* @see LayoutData#groupHeight
* @see LayoutData#groupWidth
*/
  static void calculateLayoutGroupDimensions();
};

#endif
