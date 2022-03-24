/*
 * Copyright (c) 2022. Uniontech Software Ltd. All rights reserved.
 *
 * Author:     chenhuixing <chenhuixing@uniontech.com>
 *
 * Maintainer: chenhuixing <chenhuixing@uniontech.com>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "source_fetcher.h"

#include <QEventLoop>

#include "module/util/http_client.h"
#include "module/util/runner.h"
#include "module/util/fs.h"

namespace linglong {
namespace builder {

class SourceFetcherPrivate
{
public:
    explicit SourceFetcherPrivate(Source *src, SourceFetcher *parent);
    ~SourceFetcherPrivate() = default;

    QString filename();

    // TODO: use share cache for all project
    QString sourceTargetPath() const;

    util::Error fetchArchiveFile();

    util::Error fetchGitRepo() const;

    util::Error handleDebianPatch() const;

    util::Error handleLocalPatch() const;

    Project *project;
    Source *source;
    QScopedPointer<QFile> file;

    SourceFetcher *const q_ptr;
    Q_DECLARE_PUBLIC(SourceFetcher)
};
} // namespace builder
} // namespace linglong