#ifndef __SHADERLAYER_H__
#define __SHADERLAYER_H__


#include "includes.h"



class ShaderLayer : cocos2d::CCLayer { 
    
	static ShaderLayer* create();

	// TodoReturn objectPosToShaderPos(cocos2d::CCPoint);
	// TodoReturn performCalculations();
	// TodoReturn preBulgeShader();
	// TodoReturn preChromaticGlitchShader();
	// TodoReturn preChromaticShader();
	// TodoReturn preColorChangeShader();
	// TodoReturn preCommonShader();
	// TodoReturn preGlitchShader();
	// TodoReturn preGrayscaleShader();
	// TodoReturn preHueShiftShader();
	// TodoReturn preInvertColorShader();
	// TodoReturn preLensCircleShader();
	// TodoReturn preMotionBlurShader();
	// TodoReturn prepareTargetContainer();
	// TodoReturn prePinchShader();
	// TodoReturn prePixelateShader();
	// TodoReturn preRadialBlurShader();
	// TodoReturn preSepiaShader();
	// TodoReturn preShockLineShader();
	// TodoReturn preShockWaveShader();
	// TodoReturn preSplitScreenShader();
	// TodoReturn resetAllShaders();
	// TodoReturn resetTargetContainer();
	void setupBulgeShader();
	void setupChromaticGlitchUniforms();
	void setupChromaticUniforms();
	void setupColorChangeShader();
	void setupCommonUniforms();
	void setupGlitchUniforms();

    /* Freebie from Robtop's twitch stream SEE: https://youtube.com/watch?v=eBcUC9lYLdI 2:05 */
	void setupGrayscaleShader();
    void setupHueShiftShader();
	void setupInvertColorShader();
	void setupLensCircleShader();
	void setupMotionBlurShader();
	void setupPinchShader();
	void setupRadialBlurShader();
	void setupSepiaShader();
	// TodoReturn setupShader(bool);
	void setupShockLineUniforms();
	void setupShockWaveUniforms();
	void setupSplitScreenShader();
	// TodoReturn toggleAntiAlias(bool);
	// TodoReturn triggerBulge(float, float, float, float, float, int, int, float, bool);
	// TodoReturn triggerChromaticGlitch(bool, float, float, float, float, float, float, float, int, float, bool, bool);
	// TodoReturn triggerChromaticX(float, float, int, float, bool);
	// TodoReturn triggerChromaticY(float, float, int, float, bool);
	// TodoReturn triggerColorChange(float, float, float, float, float, float, float, int, float);
	// TodoReturn triggerGlitch(float, float, float, float, float, float, float, bool);
	// TodoReturn triggerGrayscale(float, float, bool, int, int, float);
	// TodoReturn triggerHueShift(float, float, int, float);
	// TodoReturn triggerInvertColor(float, float, float, float, float, bool, bool, bool, int, float);
	// TodoReturn triggerLensCircle(float, float, float, float, int, int, float, float, int, float, bool);
	// TodoReturn triggerMotionBlurX(float, float, float, float, int, float, bool, int, int, float, bool, bool);
	// TodoReturn triggerMotionBlurY(float, float, float, float, int, float, bool, int, int, float, bool, bool);
	// TodoReturn triggerPinchX(float, float, float, float, float, bool, int, int, float, bool);
	// TodoReturn triggerPinchY(float, float, float, float, float, bool, int, int, float, bool);
	// TodoReturn triggerPixelateX(float, float, bool, bool, int, float, bool);
	// TodoReturn triggerPixelateY(float, float, bool, bool, int, float, bool);
	// TodoReturn triggerRadialBlur(float, float, float, float, int, float, float, bool, int, int, float, bool);
	// TodoReturn triggerSepia(float, float, int, float);
	// TodoReturn triggerShockLine(float, float, bool, bool, bool, bool, float, float, float, float, float, float, int, bool, bool, bool, float, bool, float, int, float);
	// TodoReturn triggerShockWave(float, float, float, float, float, float, float, bool, float, float, float, int, bool, bool, bool, float, float, bool, float, int, float);
	// TodoReturn triggerSplitScreenCols(float, float, int, float);
	// TodoReturn triggerSplitScreenRows(float, float, int, float);
	// TodoReturn tweenValue(float, float, int, float, int, float);
	// TodoReturn tweenValueAuto(float, int, float, int, float);
	// TodoReturn updateEffectOffsets(cocos2d::CCPoint);
	// TodoReturn updateMotionBlurSpeedX(float, float);
	// TodoReturn updateMotionBlurSpeedY(float, float);
	// TodoReturn updateShockLineCenter(cocos2d::CCPoint);
	// TodoReturn updateShockWaveCenter(cocos2d::CCPoint);
	// TodoReturn updateZLayer(int, int, bool);

	virtual void update(float);
	virtual bool init();
	virtual void visit();

	/* Real Name in Robtop's code is _rendTexSprite we add the "m" 
	 * because for Geode's sake otherwise I would've named 
	 * it by Robtop's own code - Calloc */
	cocos2d::CCSprite* m_rendTexSprite;	
	int m_textureScaleLoc;
	int m_textureScaleInvLoc;
	int m_shaderPositionLoc;
	int m_blurRefColorLoc;
	int m_blurUseRefLoc;
	int m_blurIntensityLoc;
	int m_blurOnlyEmptyLoc;
	int m_shockWaveTimeLoc;
	int m_shockWaveTime1Loc;
	int m_shockWaveTime2Loc;
	int m_shockWaveTime3Loc;
	int m_shockWaveTime4Loc;
	int m_shockWaveStrengthLoc;
	int m_shockWaveWavesLoc;
	int m_shockWaveCenterLoc;
	int m_shockWaveInvertLoc;
	int m_shockWaveMinSizeLoc;
	int m_shockWaveMaxSizeLoc;
	int m_shockWaveMaxDistValLoc;	
	
	int m_shockLineTimeLoc;
	int m_shockLineTime1Loc;
	int m_shockLineTime2Loc;
	int m_shockLineTime3Loc;
	int m_shockLineTime4Loc;
	int m_shockLineAxisLoc;
	int m_shockLineDirectionLoc;
	int m_shockLineDualLoc;
	int m_shockLineWavesLoc;
	int m_shockLineStrengthLoc;
	int m_shockLineCenterLoc;
	int m_shockLineMaxDistVal;	
	int m_glichBotLoc;
	int m_glitchTopLoc;
	int m_glichXOffsetLoc;
	int m_glitchColOffSetLoc;
	int m_glichRndLoc;
	int m_chromaticXOffLoc;
	int m_chromaticYOffLoc;
	int m_cGRGBOffsetLoc;
	int m_cGYOffsetLoc;
	int m_cGTimeLoc;	
	int m_cGStrengthLoc;
	int m_cGHeightLoc;
	int m_cGLineThickLoc;
	int m_cGLineStrength;
	int m_lensCircleOriginLoc;
	int m_lensCircleStartLoc;
	int m_lensCircleEndLoc;
	int m_lensCircleStrengthLoc;
	int m_lensCircleTintLoc;
	int m_lensCircleAdditiveLoc;
	int m_radialBlurCenter;
	int m_raidialBlurValue;
	int m_blurFadeLoc;
	int m_motionBlurValueLoc;
	int m_motionBlurMultLoc;
	int m_motionBlurDualLoc;
	int m_bulgeValueLoc;
	int m_bulgeValue2Loc;
	int m_bulgeOriginLoc;
	int m_bulgeRadiusLoc;
	int m_pinchValueLoc;
	int m_pinchCenterPos;
	int m_pinchCalc1Loc;
	int m_pinchRadiusLoc;
	int m_grayscaleValueLoc;
	int m_grayscaleTintLoc;
	int m_grayscaleUseLumLoc;
	int m_sepiaValueLoc;
	int m_invertColorValueLoc;
	int m_hueShiftCosALoc;
	int m_hueShiftSinALoc;
	int m_colorChangeCLoc;
	int m_colorChangeBLoc;
	int m_rowmodLoc;
	int m_colmodLoc;
	int m_rowmodCalcLoc;
	int m_colmodCalcLoc;
	int m_splitXStartLoc;
	int m_splitXRangeLoc;
	int m_splitXRangeMultLoc;
	int m_splitYStartLoc;
	int m_splitYRangeLoc;
	int m_splitYRangeMultLoc;
}

#endif // __SHADERLAYER_H__
