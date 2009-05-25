/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8-*- */
/*
 * freetuxtv
 * Copyright (C) FreetuxTV Team's 2008
 * Project homepage : http://code.google.com/p/freetuxtv/
 * 
 * freetuxtv is free software.
 * 
 */

#ifndef FREETUXTV_PLAYER_H
#define FREETUXTV_PLAYER_H

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <glib-object.h>
#include <gtk/gtk.h>
#if LIBVLC_VERSION_MAJOR == 0 && LIBVLC_VERSION_MINOR == 9
#include <vlc/vlc.h>
#endif
#if LIBVLC_VERSION_MAJOR == 0 && LIBVLC_VERSION_MINOR == 8
#include <vlc/libvlc.h>
#endif

#include "freetuxtv-channel-infos.h"

G_BEGIN_DECLS

#define FREETUXTV_TYPE_PLAYER            (freetuxtv_player_get_type ())
#define FREETUXTV_PLAYER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), FREETUXTV_TYPE_PLAYER, FreetuxTVPlayer))
#define FREETUXTV_PLAYER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), FREETUXTV_TYPE_PLAYER, FreetuxTVPlayerClass))
#define FREETUXTV_IS_PLAYER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FREETUXTV_TYPE_PLAYER))
#define FREETUXTV_IS_PLAYER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FREETUXTV_TYPE_PLAYER))
#define FREETUXTV_PLAYER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), FREETUXTV_TYPE_PLAYER, FreetuxTVPlayerClass))

typedef struct _FreetuxTVPlayer FreetuxTVPlayer;
typedef struct _FreetuxTVPlayerClass FreetuxTVPlayerClass;

struct _FreetuxTVPlayer
{
	GtkDrawingArea parent;
	
	gdouble volume;
	
	struct {
		libvlc_instance_t *inst;
#if LIBVLC_VERSION_MAJOR == 0 && LIBVLC_VERSION_MINOR == 9
		libvlc_media_player_t *mp;
#endif
	} libvlc;

	gboolean is_recording;
};

struct _FreetuxTVPlayerClass
{
	GtkDrawingAreaClass parent_class;
};

GType
freetuxtv_player_get_type (void);

GtkWidget *
freetuxtv_player_new ();

void
freetuxtv_player_play (FreetuxTVPlayer *self, FreetuxTVChannelInfos *channel_infos);

void
freetuxtv_player_set_volume (FreetuxTVPlayer *self, gdouble value);

gdouble
freetuxtv_player_get_volume (FreetuxTVPlayer *self);

void
freetuxtv_player_stop (FreetuxTVPlayer *self);

void
freetuxtv_player_record_current (FreetuxTVPlayer *self, gchar* directory_record, gchar** out_filename);

void
freetuxtv_player_fullscreen (FreetuxTVPlayer *self);

gboolean
freetuxtv_player_is_playing(FreetuxTVPlayer *self);

gboolean
freetuxtv_player_is_recording(FreetuxTVPlayer *self);

G_END_DECLS

#endif /* FREETUXTV_PLAYER_H */
