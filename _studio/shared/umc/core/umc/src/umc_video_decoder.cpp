// Copyright (c) 2017 Intel Corporation
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <string.h>
#include "umc_video_decoder.h"

namespace UMC
{

VideoDecoderParams::VideoDecoderParams(void)
{
    m_pData = NULL;
    memset(&info, 0, sizeof(sVideoStreamInfo));
    lFlags = 0;
    pPostProcessing = NULL;
    lpMemoryAllocator = NULL;
    pVideoAccelerator = NULL;
} // VideoDecoderParams::VideoDecoderParams(void)

VideoDecoderParams::~VideoDecoderParams(void)
{

} // VideoDecoderParams::~VideoDecoderParams(void)

VideoDecoder::~VideoDecoder(void)
{
  if (m_allocatedPostProcessing) {
    delete m_allocatedPostProcessing;
    m_allocatedPostProcessing = NULL;
  }
} // VideoDecoder::~VideoDecoder(void)

Status VideoDecoder::GetInfo(BaseCodecParams *info)
{
    Status umcRes = UMC_OK;
    VideoDecoderParams *pParams = DynamicCast<VideoDecoderParams> (info);

    if (NULL == pParams)
        return UMC_ERR_NULL_PTR;

    pParams->info = m_ClipInfo;

    return umcRes;

} // Status VideoDecoder::GetInfo(BaseCodecParams *info)

Status VideoDecoder::SetParams(BaseCodecParams* params)
{
    Status umcRes = UMC_OK;
    VideoDecoderParams *pParams = DynamicCast<VideoDecoderParams>(params);

    if (NULL == pParams)
        return UMC_ERR_NULL_PTR;

    m_ClipInfo = pParams->info;

    return umcRes;

} // Status VideoDecoder::SetParams(BaseCodecParams* params)

} // end namespace UMC