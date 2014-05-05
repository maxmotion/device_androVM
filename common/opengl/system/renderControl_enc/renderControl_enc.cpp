// Generated Code - DO NOT EDIT !!
// generated by 'emugen'


#include <string.h>
#include "renderControl_opcodes.h"

#include "renderControl_enc.h"


#include <stdio.h>
static void enc_unsupported()
{
	ALOGE("Function is unsupported\n");
}

GLint rcGetRendererVersion_enc(void *self )
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	 unsigned char *ptr;
	 const size_t packetSize = 8;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcGetRendererVersion; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;

	GLint retval;
	stream->readback(&retval, 4);
	return retval;
}

EGLint rcGetEGLVersion_enc(void *self , EGLint* major, EGLint* minor)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	const unsigned int __size_major =  sizeof(EGLint);
	const unsigned int __size_minor =  sizeof(EGLint);
	 unsigned char *ptr;
	 const size_t packetSize = 8 + __size_major + __size_minor + 2*4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcGetEGLVersion; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(unsigned int *)(ptr) = __size_major; ptr += 4;
	*(unsigned int *)(ptr) = __size_minor; ptr += 4;
	stream->readback(major, __size_major);
	stream->readback(minor, __size_minor);

	EGLint retval;
	stream->readback(&retval, 4);
	return retval;
}

EGLint rcQueryEGLString_enc(void *self , EGLenum name, void* buffer, EGLint bufferSize)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	const unsigned int __size_buffer =  bufferSize;
	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4 + __size_buffer + 4 + 1*4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcQueryEGLString; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(EGLenum *) (ptr) = name; ptr += 4;
	*(unsigned int *)(ptr) = __size_buffer; ptr += 4;
	*(EGLint *) (ptr) = bufferSize; ptr += 4;
	stream->readback(buffer, __size_buffer);

	EGLint retval;
	stream->readback(&retval, 4);
	return retval;
}

EGLint rcGetGLString_enc(void *self , EGLenum name, void* buffer, EGLint bufferSize)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	const unsigned int __size_buffer =  bufferSize;
	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4 + __size_buffer + 4 + 1*4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcGetGLString; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(EGLenum *) (ptr) = name; ptr += 4;
	*(unsigned int *)(ptr) = __size_buffer; ptr += 4;
	*(EGLint *) (ptr) = bufferSize; ptr += 4;
	stream->readback(buffer, __size_buffer);

	EGLint retval;
	stream->readback(&retval, 4);
	return retval;
}

EGLint rcGetNumConfigs_enc(void *self , uint32_t* numAttribs)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	const unsigned int __size_numAttribs =  sizeof(uint32_t);
	 unsigned char *ptr;
	 const size_t packetSize = 8 + __size_numAttribs + 1*4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcGetNumConfigs; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(unsigned int *)(ptr) = __size_numAttribs; ptr += 4;
	stream->readback(numAttribs, __size_numAttribs);

	EGLint retval;
	stream->readback(&retval, 4);
	return retval;
}

EGLint rcGetConfigs_enc(void *self , uint32_t bufSize, GLuint* buffer)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	const unsigned int __size_buffer =  bufSize;
	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4 + __size_buffer + 1*4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcGetConfigs; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(uint32_t *) (ptr) = bufSize; ptr += 4;
	*(unsigned int *)(ptr) = __size_buffer; ptr += 4;
	stream->readback(buffer, __size_buffer);

	EGLint retval;
	stream->readback(&retval, 4);
	return retval;
}

EGLint rcChooseConfig_enc(void *self , EGLint* attribs, uint32_t attribs_size, uint32_t* configs, uint32_t configs_size)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	const unsigned int __size_attribs =  attribs_size;
	const unsigned int __size_configs = ((configs != NULL) ?  configs_size*sizeof(uint32_t) : 0);
	 unsigned char *ptr;
	 const size_t packetSize = 8 + __size_attribs + 4 + __size_configs + 4 + 2*4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcChooseConfig; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(unsigned int *)(ptr) = __size_attribs; ptr += 4;
	memcpy(ptr, attribs, __size_attribs);ptr += __size_attribs;
	*(uint32_t *) (ptr) = attribs_size; ptr += 4;
	*(unsigned int *)(ptr) = __size_configs; ptr += 4;
	*(uint32_t *) (ptr) = configs_size; ptr += 4;
	if (configs != NULL) stream->readback(configs, __size_configs);

	EGLint retval;
	stream->readback(&retval, 4);
	return retval;
}

EGLint rcGetFBParam_enc(void *self , EGLint param)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcGetFBParam; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(EGLint *) (ptr) = param; ptr += 4;

	EGLint retval;
	stream->readback(&retval, 4);
	return retval;
}

uint32_t rcCreateContext_enc(void *self , uint32_t config, uint32_t share, uint32_t glVersion)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4 + 4 + 4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcCreateContext; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(uint32_t *) (ptr) = config; ptr += 4;
	*(uint32_t *) (ptr) = share; ptr += 4;
	*(uint32_t *) (ptr) = glVersion; ptr += 4;

	uint32_t retval;
	stream->readback(&retval, 4);
	return retval;
}

void rcDestroyContext_enc(void *self , uint32_t context)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcDestroyContext; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(uint32_t *) (ptr) = context; ptr += 4;
}

uint32_t rcCreateWindowSurface_enc(void *self , uint32_t config, uint32_t width, uint32_t height)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4 + 4 + 4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcCreateWindowSurface; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(uint32_t *) (ptr) = config; ptr += 4;
	*(uint32_t *) (ptr) = width; ptr += 4;
	*(uint32_t *) (ptr) = height; ptr += 4;

	uint32_t retval;
	stream->readback(&retval, 4);
	return retval;
}

void rcDestroyWindowSurface_enc(void *self , uint32_t windowSurface)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcDestroyWindowSurface; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(uint32_t *) (ptr) = windowSurface; ptr += 4;
}

uint32_t rcCreateColorBuffer_enc(void *self , uint32_t width, uint32_t height, GLenum internalFormat)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4 + 4 + 4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcCreateColorBuffer; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(uint32_t *) (ptr) = width; ptr += 4;
	*(uint32_t *) (ptr) = height; ptr += 4;
	*(GLenum *) (ptr) = internalFormat; ptr += 4;

	uint32_t retval;
	stream->readback(&retval, 4);
	return retval;
}

void rcOpenColorBuffer_enc(void *self , uint32_t colorbuffer)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcOpenColorBuffer; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(uint32_t *) (ptr) = colorbuffer; ptr += 4;
}

void rcCloseColorBuffer_enc(void *self , uint32_t colorbuffer)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcCloseColorBuffer; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(uint32_t *) (ptr) = colorbuffer; ptr += 4;
}

void rcSetWindowColorBuffer_enc(void *self , uint32_t windowSurface, uint32_t colorBuffer)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4 + 4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcSetWindowColorBuffer; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(uint32_t *) (ptr) = windowSurface; ptr += 4;
	*(uint32_t *) (ptr) = colorBuffer; ptr += 4;
}

int rcFlushWindowColorBuffer_enc(void *self , uint32_t windowSurface)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcFlushWindowColorBuffer; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(uint32_t *) (ptr) = windowSurface; ptr += 4;

	int retval;
	stream->readback(&retval, 4);
	return retval;
}

EGLint rcMakeCurrent_enc(void *self , uint32_t context, uint32_t drawSurf, uint32_t readSurf)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4 + 4 + 4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcMakeCurrent; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(uint32_t *) (ptr) = context; ptr += 4;
	*(uint32_t *) (ptr) = drawSurf; ptr += 4;
	*(uint32_t *) (ptr) = readSurf; ptr += 4;

	EGLint retval;
	stream->readback(&retval, 4);
	return retval;
}

void rcFBPost_enc(void *self , uint32_t colorBuffer)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcFBPost; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(uint32_t *) (ptr) = colorBuffer; ptr += 4;
}

void rcFBSetSwapInterval_enc(void *self , EGLint interval)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcFBSetSwapInterval; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(EGLint *) (ptr) = interval; ptr += 4;
}

void rcBindTexture_enc(void *self , uint32_t colorBuffer)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcBindTexture; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(uint32_t *) (ptr) = colorBuffer; ptr += 4;
}

void rcBindRenderbuffer_enc(void *self , uint32_t colorBuffer)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcBindRenderbuffer; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(uint32_t *) (ptr) = colorBuffer; ptr += 4;
}

EGLint rcColorBufferCacheFlush_enc(void *self , uint32_t colorbuffer, EGLint postCount, int forRead)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4 + 4 + 4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcColorBufferCacheFlush; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(uint32_t *) (ptr) = colorbuffer; ptr += 4;
	*(EGLint *) (ptr) = postCount; ptr += 4;
	*(int *) (ptr) = forRead; ptr += 4;

	EGLint retval;
	stream->readback(&retval, 4);
	return retval;
}

void rcReadColorBuffer_enc(void *self , uint32_t colorbuffer, GLint x, GLint y, GLint width, GLint height, GLenum format, GLenum type, void* pixels)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	const unsigned int __size_pixels =  (((glUtilsPixelBitSize(format, type) * width) >> 3) * height);
	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + __size_pixels + 1*4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcReadColorBuffer; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(uint32_t *) (ptr) = colorbuffer; ptr += 4;
	*(GLint *) (ptr) = x; ptr += 4;
	*(GLint *) (ptr) = y; ptr += 4;
	*(GLint *) (ptr) = width; ptr += 4;
	*(GLint *) (ptr) = height; ptr += 4;
	*(GLenum *) (ptr) = format; ptr += 4;
	*(GLenum *) (ptr) = type; ptr += 4;
	*(unsigned int *)(ptr) = __size_pixels; ptr += 4;
	stream->readback(pixels, __size_pixels);
}

int rcUpdateColorBuffer_enc(void *self , uint32_t colorbuffer, GLint x, GLint y, GLint width, GLint height, GLenum format, GLenum type, void* pixels)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	const unsigned int __size_pixels =  (((glUtilsPixelBitSize(format, type) * width) >> 3) * height);
	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + __size_pixels + 1*4;
	ptr = stream->alloc(8 + 4 + 4 + 4 + 4 + 4 + 4 + 4);
	*(unsigned int *)(ptr) = OP_rcUpdateColorBuffer; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(uint32_t *) (ptr) = colorbuffer; ptr += 4;
	*(GLint *) (ptr) = x; ptr += 4;
	*(GLint *) (ptr) = y; ptr += 4;
	*(GLint *) (ptr) = width; ptr += 4;
	*(GLint *) (ptr) = height; ptr += 4;
	*(GLenum *) (ptr) = format; ptr += 4;
	*(GLenum *) (ptr) = type; ptr += 4;
	stream->flush();
	stream->writeFully(&__size_pixels,4);
	stream->writeFully(pixels, __size_pixels);

	int retval;
	stream->readback(&retval, 4);
	return retval;
}

void rcSetOrientation_enc(void *self , uint32_t orientation)
{

	renderControl_encoder_context_t *ctx = (renderControl_encoder_context_t *)self;
	IOStream *stream = ctx->m_stream;

	 unsigned char *ptr;
	 const size_t packetSize = 8 + 4;
	ptr = stream->alloc(packetSize);
	*(unsigned int *)(ptr) = OP_rcSetOrientation; ptr += 4;
	*(unsigned int *)(ptr) = (unsigned int) packetSize; ptr += 4;
	*(uint32_t *) (ptr) = orientation; ptr += 4;
}

renderControl_encoder_context_t::renderControl_encoder_context_t(IOStream *stream)
{
	m_stream = stream;

	set_rcGetRendererVersion(rcGetRendererVersion_enc);
	set_rcGetEGLVersion(rcGetEGLVersion_enc);
	set_rcQueryEGLString(rcQueryEGLString_enc);
	set_rcGetGLString(rcGetGLString_enc);
	set_rcGetNumConfigs(rcGetNumConfigs_enc);
	set_rcGetConfigs(rcGetConfigs_enc);
	set_rcChooseConfig(rcChooseConfig_enc);
	set_rcGetFBParam(rcGetFBParam_enc);
	set_rcCreateContext(rcCreateContext_enc);
	set_rcDestroyContext(rcDestroyContext_enc);
	set_rcCreateWindowSurface(rcCreateWindowSurface_enc);
	set_rcDestroyWindowSurface(rcDestroyWindowSurface_enc);
	set_rcCreateColorBuffer(rcCreateColorBuffer_enc);
	set_rcOpenColorBuffer(rcOpenColorBuffer_enc);
	set_rcCloseColorBuffer(rcCloseColorBuffer_enc);
	set_rcSetWindowColorBuffer(rcSetWindowColorBuffer_enc);
	set_rcFlushWindowColorBuffer(rcFlushWindowColorBuffer_enc);
	set_rcMakeCurrent(rcMakeCurrent_enc);
	set_rcFBPost(rcFBPost_enc);
	set_rcFBSetSwapInterval(rcFBSetSwapInterval_enc);
	set_rcBindTexture(rcBindTexture_enc);
	set_rcBindRenderbuffer(rcBindRenderbuffer_enc);
	set_rcColorBufferCacheFlush(rcColorBufferCacheFlush_enc);
	set_rcReadColorBuffer(rcReadColorBuffer_enc);
	set_rcUpdateColorBuffer(rcUpdateColorBuffer_enc);
	set_rcSetOrientation(rcSetOrientation_enc);
}

