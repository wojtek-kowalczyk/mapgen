#pragma once

namespace config
{
    inline constexpr int DEFAULT_PREVIEW_WIDTH{600};
    inline constexpr int DEFAULT_PREVIEW_HEIGHT{600};
    inline constexpr int SETTINGS_PANEL_WIDTH{300};
    inline constexpr int MIN_IMAGE_SIZE{1};
    inline constexpr int MAX_IMAGE_SIZE{16'384};
    inline constexpr int DEAFULT_IMAGE_WIDTH{50};
    inline constexpr int DEAFULT_IMAGE_HEIGHT{50};
    inline constexpr int WHITE{255};
    inline constexpr int BLACK{0};

    inline const char* ALG_NAME_WHITE_NOISE{"White Noise"};
    inline const char* ALG_NAME_CELLULAR_AUTOMATA{"Cellular Automata"};
    inline const char* GENERATE_BUTTON_TEXT{"Generate"};
    inline const char* SAVE_BUTTON_TEXT{"Save as..."};
} // namespace config
