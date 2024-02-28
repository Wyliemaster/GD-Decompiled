#include "../includes.h"


void ShaderLayer::setupBulgeShader()
{
    m_bulgeValueLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_bulgeValue");
    m_bulgeValue2Loc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_bulgeValue2");
    m_bulgeOriginLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_bulgeOrigin");
    m_bulgeRadiusLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_bulgeRadius");
}

void ShaderLayer::setupChromaticGlitchUniforms()
{
    m_cGRGBOffsetLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_cGRGBOffset");
    m_cGYOffsetLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_cGYOffset");
    m_cGTimeLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_cGTime"); ;
    m_cGStrengthLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_cGStrength");
    m_cGHeightLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_cGHeight");
    m_cGLineThickLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_cGLineThick");
    m_cGLineStrength = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_cGLineStrength");
}


void ShaderLayer::setupChromaticUniforms()
{
    m_chromaticXOffLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_chromaticXOff");
    m_chromaticYOffLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_chromaticYOff");
}

void ShaderLayer::setupColorChangeShader()
{
    m_colorChangeCLoc  = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_colorChangeC");
    m_colorChangeBLoc  = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_colorChangeB");
}


void ShaderLayer::setupGlitchUniforms()
{
    m_glichBotLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_glitchBot");
    m_glitchTopLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_glitchTop");
    m_glichXOffsetLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_glitchXOffset");
    m_glitchColOffSetLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_glitchColOffset");
    m_glichRndLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_glitchRnd");
}


/* NOTE: Some Functions shown are Freebies from Robtop's Own Twitch Stream */

void ShaderLayer::setupGrayscaleShader()
{
    m_grayscaleValueLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(), "_grayscaleValue");
    m_grayscaleTintLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(), "_grayscaleTint");
    m_grayscaleUseLumLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(), "_grayscaleUseLum");
}

void ShaderLayer::setupHueShiftShader()
{
    m_hueShiftCosALoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(), "_hueShiftCosA");
    m_hueShiftSinALoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(), "_hueShiftSinA");
}

void ShaderLayer::setupInvertColorShader()
{
    m_invertColorValueLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_invertColorValue");
}

void ShaderLayer::setupLensCircleShader()
{
    m_lensCircleOriginLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_lensCircleOrigin");
    m_lensCircleStartLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_lensCircleStart");
    m_lensCircleEndLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_lensCircleEnd"); 
    m_lensCircleStrengthLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_lensCircleStrength");
    m_lensCircleTintLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_lensCircleTint");
    m_lensCircleAdditiveLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_lensCircleAdditive");
}


void ShaderLayer::setupMotionBlurShader()
{
    m_motionBlurValueLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_motionBlurValue");
    m_motionBlurMultLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_motionBlurMult");
    m_motionBlurDualLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_motionBlurDual"); ;
}

void ShaderLayer::setupPinchShader()
{
    m_pinchValueLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_pinchValue");
    m_pinchCenterPos = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_pinchCenterPos");
    m_pinchCalc1Loc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_pinchCalc1");
    m_pinchRadiusLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_pinchRadius");

}

void ShaderLayer::setupRadialBlurShader()
{
    m_radialBlurCenter = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_radialBlurCenter"); 
    m_raidialBlurValue = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_radialBlurValue");
}

void ShaderLayer::setupSepiaShader()
{
    m_sepiaValueLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_sepiaValue");
}

void ShaderLayer::setupShockLineUniforms()
{
    m_shockLineTimeLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_shockLineTime");
    m_shockLineTime1Loc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_shockLineTime1");
    m_shockLineTime2Loc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_shockLineTime2"); 
    m_shockLineTime3Loc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_shockLineTime3");
    m_shockLineTime4Loc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_shockLineTime4"); 
    m_shockLineAxisLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_shockLineAxis");
    m_shockLineDirectionLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_shockLineDirection");
    m_shockLineDualLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_shockLineDual");
    m_shockLineWavesLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_shockLineWaves");
    m_shockLineStrengthLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_shockLineStrength");
    m_shockLineCenterLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_shockLineCenter");
    m_shockLineMaxDistVal = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_shockLineMaxDistVal");
}


void ShaderLayer::setupSplitScreenShader()
{
    m_rowmodLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_rowmod");
    m_colmodLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_colmod");
    m_rowmodCalcLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_rowmodCalc");
    m_colmodCalcLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_colmodCalc");
    m_splitXStartLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_splitXStart");
    m_splitXRangeLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_splitXRange");
    m_splitXRangeMultLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_splitXRangeMult");
    m_splitYStartLoc =  glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_splitYStart");
    m_splitYRangeLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_splitYRange");
    m_splitYRangeMultLoc = glGetUniformLocation(m_rendTexSprite->getShaderProgram()->getProgram(),"_splitYRangeMult");
}
