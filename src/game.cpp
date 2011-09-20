/*
 * This file is part of the Marmalade SDK Code Samples.
 *
 * Copyright (C) 2001-2011 Ideaworks3D Ltd.
 * All Rights Reserved.
 *
 * This source code is intended only as a supplement to Ideaworks Labs
 * Development Tools and/or on-line documentation.
 *
 * THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 */
#include "s3e.h"
#include "Iw2D.h"
#include "game.h"

CGame::CGame()
: m_Position(0,0)
{
	m_ImgBG = Iw2DCreateImage("game-bg.png");
	m_ImgKey = Iw2DCreateImage("key.png");
}


CGame::~CGame()
{
	delete m_ImgBG;
	delete m_ImgKey;
}


void CGame::Update()
{
    // game logic goes here

    // for example, move a red square towards any touch event...
    if( s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_DOWN )
    {
        CIwFVec2 target((float)s3ePointerGetX(), (float)s3ePointerGetY());

        m_Position += (target - m_Position) * 0.05f;
    }
}


void CGame::Render()
{
    // game render goes here

    // for example, clear to black (the order of components is ABGR)
    Iw2DSurfaceClear(0xff000000);

	Iw2DDrawImage(m_ImgBG, CIwSVec2(0,0));
	Iw2DDrawImage(m_ImgKey, CIwSVec2(m_Position.x, m_Position.y));

    // show the surface
    Iw2DSurfaceShow();
}
