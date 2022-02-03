#pragma once

namespace config
{
    inline constexpr int DEFAULT_PREVIEW_WIDTH{600};
    inline constexpr int DEFAULT_PREVIEW_HEIGHT{600};
    inline constexpr int MIN_PREVIEW_WIDTH{300};
    inline constexpr int MIN_PREVIEW_HEIGHT{300};
    inline constexpr int SETTINGS_PANEL_WIDTH{300};
    inline constexpr int MIN_IMAGE_SIZE{1};
    inline constexpr int MAX_IMAGE_SIZE{16'384};
    inline constexpr int DEAFULT_IMAGE_WIDTH_SMALL{64};
    inline constexpr int DEAFULT_IMAGE_HEIGHT_SMALL{64};
    inline constexpr int DEAFULT_IMAGE_WIDTH_MEDIUM{512};
    inline constexpr int DEAFULT_IMAGE_HEIGHT_MEDIUM{512};
    inline constexpr int DEAFULT_IMAGE_WIDTH_LARGE{2048};
    inline constexpr int DEAFULT_IMAGE_HEIGHT_LARGE{2048};
    inline constexpr int DEFAULT_FILL_PERCENT{50};
    inline constexpr int WHITE{255};
    inline constexpr int BLACK{0};

    inline const char* ALG_NAME_WHITE_NOISE{"White Noise"};
    inline const char* ALG_NAME_CELLULAR_AUTOMATA{"Cellular Automata"};
    inline const char* ALG_NAME_PERLIN_NOISE{"Perlin Noise"};
    inline const char* GENERATE_BUTTON_TEXT{"Generate"};
    inline const char* SAVE_BUTTON_TEXT{"Save as..."};
} // namespace config
